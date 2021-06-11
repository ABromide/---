#include "stdio.h"
#define N 5
#define M 4
int xs_plus(char *p,char *q);
int zs_plus(char *p,char *q,int);
int flag=0;
int main(void)
{
    char  azs[N],axs[M];
    char  bzs[N],bxs[M];

    int carry=0,flag;
    int i,k=0;

     for (i=0;i<N;i++) scanf("%c",azs+N-1-i);
     getchar();
     for (i=0;i<M;i++) scanf("%c",axs+M-1-i);
     getchar();
     for (i=0;i<N;i++) scanf("%c",bzs+N-1-i);
     getchar();
     for (i=0;i<M;i++) scanf("%c",bxs+M-1-i);

     printf("小数部分");
     k=xs_plus(axs,bxs);

     zs_plus(azs,bzs,k);
     xs_plus(axs,bxs);
}
int xs_plus(char *p,char *q)
{
    int cxs[M];
    int *c=cxs;int i=0;
    int carry=0,flag=0;
    int a[M],b[M];

     for (i=0;i<M;i++)
     {
         *(a+i)=*(p+i)-'0';
         *(b+i)=*(q+i)-'0';
     }

    for (i=0;i<M;i++)
    {
        (*(c+i))=(*(a+i))+(*(b+i))+carry;
        if(((*(c+i)))>=9)
        {
           carry=((*(c+i)))/10;
           (*(c+i))=((*(c+i)))%10;
        }
    }
        if(carry!=0)
            {  printf(".");for(i=0;i<M;i++)  printf("%d",*(c+M-1-i));
           printf("\n"); printf("\n");
           flag=1; return flag;}

        else
            {printf(".");for (i=0;i<M;i++) printf("%d",*(c+M-1-i));}
             printf("\n");
             return flag;

}

int zs_plus(char *p,char *q,int flag)
{    int czs[N+1];
     int *c=czs;int i=0;
     int carry=0;
     int a[N],b[N];

      for (i=0;i<N;i++)
     {
         *(a+i)=*(p+i)-'0';
         *(b+i)=*(q+i)-'0';
     }
    for (i=0;i<N;i++)
    {
        (*(c+i))=( *(a+i))+(*(b+i))+carry+flag;
          flag=0;
        if((*(c+i))>=9)
        {
           carry=((*(c+i)))/10;
           *(c+i)=((*(c+i)))%10;
        }
    }

        if(carry!=0)
            {  (*(c+N))=carry;
                for (i=0;i<N+1;i++) printf("%d",*(c+N-i));
            }

        else
            for (i=0;i<N;i++) printf("%d",*(c+N-1-i));

}
