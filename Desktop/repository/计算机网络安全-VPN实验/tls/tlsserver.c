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
	SSL_library_init();			/* 为SSL加载加密和哈希算法 */   
	SSL_load_error_strings();	/* 为了更友好的报错，加载错误码的描述字符串 */
	SSLeay_add_ssl_algorithms();

	// Step 1: SSL context initialization
	meth = SSLv23_server_method();//使用SSLv23的服务器可以支持SSLv2,SSLv3以及TLSv1发来的hello消息 
	ctx = SSL_CTX_new(meth);//SSL_CTX_new函数以SSL_METHOD结构体作为参数，创建并且返回SSL_CTX结构。 
	
   //函数SSL_CTX_set_verify可以用于设置在SSL_CTX结构中的验证标记，
   //第三个函数可以设置一个指定验证过程的回调函数。（回调参数如果设置为NULL意味着用内建默认的验证方式）。
	SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, NULL);
	//SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, NULL);
	
	
	SSL_CTX_load_verify_locations(ctx, CACERT, NULL);//首先需要加载CA证书 

	// Step 2: Set up the server certificate and private key
	if (SSL_CTX_use_certificate_file(ctx, CERTF, SSL_FILETYPE_PEM) <= 0) { 
		ERR_print_errors_fp(stderr);//函数加载一个证书到一个SSL_CTX结构中
		exit(3);
	}
	if (SSL_CTX_use_PrivateKey_file(ctx, KEYF, SSL_FILETYPE_PEM) <= 0) {
		ERR_print_errors_fp(stderr);//加载私钥到SSL结构或者SSL_CTX结构中 
		exit(4);
	}
	if (!SSL_CTX_check_private_key(ctx)) {
		fprintf(stderr, "Private key does not match the certificate public key\n");
		exit(5);
	}
	// Step 3: Create a new SSL structure for a connection
	ssl = SSL_new(ctx);//建立SSL

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

			SSL_set_fd(ssl, sock);//将SSL与TCP socket连接
			int err = SSL_accept(ssl);//接受新SSL连接,握手 

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
	//socket()函数创建监听socket，
	listen_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	CHK_ERR(listen_sock, "socket");
	memset(&sa_server, '\0', sizeof(sa_server));
	sa_server.sin_family = AF_INET;
	sa_server.sin_addr.s_addr = INADDR_ANY;
	sa_server.sin_port = htons(4433);
	//使用bind函数绑定了端口和地址后，在调用listen函数后，就可以处理来自客户端的TCP/IP请求了  
	int err = bind(listen_sock, (struct sockaddr *) &sa_server, sizeof(sa_server));
 
	CHK_ERR(err, "bind");
	err = listen(listen_sock, 5);// 等待队列为5 
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
	//调用SSL_write在SSL连接上发送数据。被发送的数据存放在一个缓冲区中以第二个参数传入 
	SSL_shutdown(ssl);
	SSL_free(ssl);
}
