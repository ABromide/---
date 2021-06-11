#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(char argc, char * argv[])
{
    int fd;
    char val[] = {"abcdefghijklnmopqrstuvwxyzbcdefghijklnmopqrstuvwxyza"};
    char val2[]={"bcdefghijklnmopqrstuvwxyza"};
    fd = open("/dev/hellodev", O_RDWR);
    if(fd < 0){
        printf("can't open!\n");
    }
for(int i =0 ;i<52 ;i++){
    int a=write(fd, val+i, 1);
    printf("write %d number of %c\n",a,val[i]);
}
 //printf("%s\n",val2);

}
