#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

/* define HOME to be dir for key and cert files... */
#define HOME	"./cert_server/"

/* Make these what you want for cert & key files */
#define CERTF	HOME"server.crt"
#define KEYF	HOME"server.key"
#define CACERT	HOME"ca.crt"

#define CHK_NULL(x)	if ((x)==NULL) exit (1)
#define CHK_ERR(err,s)	if ((err)==-1) { perror(s); exit(1); }
#define CHK_SSL(err)	if ((err)==-1) { ERR_print_errors_fp(stderr); exit(2); }

int setupTCPServer();	// Defined in Listing 19.10
void processRequest(SSL * ssl, int sock);	// Defined in Listing 19.12

int main()
{
	SSL_METHOD *meth;
	SSL_CTX *ctx;
	SSL *ssl;
	int err;

	// Step 0: OpenSSL library initialization 
	// This step is no longer needed as of version 1.1.0.
	SSL_library_init();			/* ΪSSL���ؼ��ܺ͹�ϣ�㷨 */   
	SSL_load_error_strings();	/* Ϊ�˸��Ѻõı������ش�����������ַ��� */
	SSLeay_add_ssl_algorithms();

	// Step 1: SSL context initialization
	meth = SSLv23_server_method();//ʹ��SSLv23�ķ���������֧��SSLv2,SSLv3�Լ�TLSv1������hello��Ϣ 
	ctx = SSL_CTX_new(meth);//SSL_CTX_new������SSL_METHOD�ṹ����Ϊ�������������ҷ���SSL_CTX�ṹ�� 
	
   //����SSL_CTX_set_verify��������������SSL_CTX�ṹ�е���֤��ǣ�
   //������������������һ��ָ����֤���̵Ļص����������ص������������ΪNULL��ζ�����ڽ�Ĭ�ϵ���֤��ʽ����
	SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, NULL);
	//SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, NULL);
	
	
	SSL_CTX_load_verify_locations(ctx, CACERT, NULL);//������Ҫ����CA֤�� 

	// Step 2: Set up the server certificate and private key
	if (SSL_CTX_use_certificate_file(ctx, CERTF, SSL_FILETYPE_PEM) <= 0) { 
		ERR_print_errors_fp(stderr);//��������һ��֤�鵽һ��SSL_CTX�ṹ��
		exit(3);
	}
	if (SSL_CTX_use_PrivateKey_file(ctx, KEYF, SSL_FILETYPE_PEM) <= 0) {
		ERR_print_errors_fp(stderr);//����˽Կ��SSL�ṹ����SSL_CTX�ṹ�� 
		exit(4);
	}
	if (!SSL_CTX_check_private_key(ctx)) {
		fprintf(stderr, "Private key does not match the certificate public key\n");
		exit(5);
	}
	// Step 3: Create a new SSL structure for a connection
	ssl = SSL_new(ctx);//����SSL

	struct sockaddr_in sa_client;
	size_t client_len = sizeof(struct sockaddr_in);
	int listen_sock = setupTCPServer();

	fprintf(stderr, "listen_sock = %d\n", listen_sock);
	while (1) {
		int sock = accept(listen_sock, (struct sockaddr *) &sa_client, &client_len);

		fprintf(stderr, "sock = %d\n", sock);
		if (sock == -1) {
			fprintf(stderr, "Accept TCP connect failed! (%d: %s)\n", errno, strerror(errno));
			continue;
		}
		if (fork() == 0) {	// The child process
			close(listen_sock);

			SSL_set_fd(ssl, sock);//��SSL��TCP socket����
			int err = SSL_accept(ssl);//������SSL����,���� 

			fprintf(stderr, "SSL_accept return %d\n", err);
			CHK_SSL(err);
			printf("SSL connection established!\n");

			processRequest(ssl, sock);
			close(sock);
			return 0;
		} else {	// The parent process
			close(sock);
		}
	}
}

int setupTCPServer()
{
	struct sockaddr_in sa_server;
	int listen_sock;
	//socket()������������socket��
	listen_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	CHK_ERR(listen_sock, "socket");
	memset(&sa_server, '\0', sizeof(sa_server));
	sa_server.sin_family = AF_INET;
	sa_server.sin_addr.s_addr = INADDR_ANY;
	sa_server.sin_port = htons(4433);
	//ʹ��bind�������˶˿ں͵�ַ���ڵ���listen�����󣬾Ϳ��Դ������Կͻ��˵�TCP/IP������  
	int err = bind(listen_sock, (struct sockaddr *) &sa_server, sizeof(sa_server));
 
	CHK_ERR(err, "bind");
	err = listen(listen_sock, 5);// �ȴ�����Ϊ5 
	CHK_ERR(err, "listen");
	return listen_sock;
}

void processRequest(SSL * ssl, int sock)
{
	char buf[1024];
	int len = SSL_read(ssl, buf, sizeof(buf) - 1);

	buf[len] = '\0';
	printf("Received: %s\n", buf);

	// Construct and send the HTML page
	char *html = "HTTP/1.1 200 OK\r\n" "Content-Type: text/html\r\n\r\n" "<!DOCTYPE html><html>" "<head><title>Hello World</title></head>" "<style>body {background-color: black}" "h1 {font-size:3cm; text-align: center; color: white;" "text-shadow: 0 0 3mm yellow}</style></head>" "<body><h1>Hello, world!</h1></body></html>";

	SSL_write(ssl, html, strlen(html));
	//����SSL_write��SSL�����Ϸ������ݡ������͵����ݴ����һ�����������Եڶ����������� 
	SSL_shutdown(ssl);
	SSL_free(ssl);
}
