/*��4����ĳ������N��ѧ����ÿ��ѧ������M�ſγ̣���#define����N��M����
����M�ſγ̵����ƣ�Ȼ����������N��ѧ����ÿ��ѧ�����޵�M�ſγ̵ĳɼ����Ҷ���ŵ���Ӧ�������С���д���к�����
a.����ÿ��ѧ�����ſγ�ƽ���ɼ���
b.����ȫ��ÿ�ſγ̵�ƽ���ɼ���
c.�ֱ�ͳ�Ƶ���ȫ����ſγ�ƽ���ɼ���������
d.�ֱ�ͳ��ȫ����ſγ̲������������90�����ϣ���90�֣���������
�ڵ��ú������������������ļ���������Ҫ����ָ�����������ʹ���±��������*/

#include "stdio.h"
#define N 3
#define M 3
double ave_s(double *p);
double allclass_ave(double *p);
int low_a(double *p,double);
int bjg_good(double *p);
int main(void)
{
    double cj[N][M];
    char name_obj[10][10];
    double *cjj=&cj[0][0];
    int i=0,k=0,h=0,m=0,n=0;
    int a=0;
    char c;
    int b=1;

    printf("please input the names.\n");
    while(i<M){scanf("%s",&name_obj[i]);i++;}//counses

    printf("please input the score of each subject.\n");
    for(k=0;k<N;k++)
    {
        for(h=0;h<M;h++) scanf("%lf",(cjj+k*M+h));
    }
      printf("a.����ÿ��ѧ�����ſγ�ƽ���ɼ���\n");
      printf("b.����ȫ��ÿ�ſγ̵�ƽ���ɼ���\n");
      printf("c.�ֱ�ͳ�Ƶ���ȫ����ſγ�ƽ���ɼ���������\n");
      printf("d.�ֱ�ͳ��ȫ����ſγ̲������������90�����ϣ���90�֣���������\n");


      while(scanf("%c",&c)!=EOF)
        {
      switch(c)
      {
          //����ÿ��ѧ�����ſγ�ƽ���ɼ���
      case('a'):

           for(k=0;k<N;k++)
           {
            printf("student %d: ",b);b++;
            ave_s(cjj+M*k);

            }
            break;
            //����ȫ��ÿ�ſγ̵�ƽ���ɼ���
      case('b'):

           for(m=0;m<M;m++)
           {
                printf("average score of %s  ",*(name_obj+m));
                ;
                printf("score:%lf\n",allclass_ave(cjj+m));
                a++;
           }
           break;
           //�ֱ�ͳ�Ƶ���ȫ����ſγ�ƽ���ɼ���������
      case('c'):

            for(h=0;h<M;h++)
           {
            printf("the numbers of student who are lower than the average score of %s ",*(name_obj+h));
            printf("%d\n",low_a(cjj+h,allclass_ave(cjj+h)));
            a++;}
            break;
      case('d'):
          {
              //�ֱ�ͳ��ȫ����ſγ̲������������90�����ϣ���90�֣���������
              for(n=0;n<M;n++  )
           {
            printf("the numbers of student who are lower than 60 and higher than 90 of %s ",*(name_obj+n));
            bjg_good(cjj+n);
            a++;}
            break;
      }}

}
  return 0;
}

double ave_s(double *a)// //����ÿ��ѧ�����ſγ�ƽ���ɼ���
{

    int i=0;
    double ave,sum=0;
    for(;i<M;i++)
        sum=sum+a[i];
       ave=sum/M;
        printf("score: %f \n",ave);
      return 0;
            }

double allclass_ave(double *a)
{
    double *p=a;
    int i=0;
    double ave=0;
    for(;i<N;i++)
        ave+=*(p+i*M);
       ave=ave/(double)N;
    return ave;
}

int low_a(double *a,double ave)
{
    double *p=a;
    int i=0,count=0;
    for(;i<N;i++) {if(*(p+i*M)<ave) count++;}
    return count;
}

int bjg_good(double *a)
{

    double *p=a;
   static int k=0;
    int i=0,count1=0,count2=0;
    for(i=0;i<N;i++)
        {if(*(p+i*M)<60) count1++;
    else if(*(p+i*M)>=90) count2++;}
    printf("%d and %d \n",count1,count2);
    k=k+1;
    return 0;
}
