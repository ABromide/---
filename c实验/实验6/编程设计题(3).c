/*（4）设某个班有N个学生，每个学生修了M门课程（用#define定义N、M）。
输入M门课程的名称，然后依次输入N个学生中每个学生所修的M门课程的成绩并且都存放到相应的数组中。编写下列函数：
a.计算每个学生各门课程平均成绩；
b.计算全班每门课程的平均成绩；
c.分别统计低于全班各门课程平均成绩的人数；
d.分别统计全班各门课程不及格的人数和90分以上（含90分）的人数。
在调用函数中输出上面各函数的计算结果。（要求都用指针操作，不得使用下标操作。）*/

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
      printf("a.计算每个学生各门课程平均成绩；\n");
      printf("b.计算全班每门课程的平均成绩；\n");
      printf("c.分别统计低于全班各门课程平均成绩的人数；\n");
      printf("d.分别统计全班各门课程不及格的人数和90分以上（含90分）的人数。\n");


      while(scanf("%c",&c)!=EOF)
        {
      switch(c)
      {
          //计算每个学生各门课程平均成绩；
      case('a'):

           for(k=0;k<N;k++)
           {
            printf("student %d: ",b);b++;
            ave_s(cjj+M*k);

            }
            break;
            //计算全班每门课程的平均成绩；
      case('b'):

           for(m=0;m<M;m++)
           {
                printf("average score of %s  ",*(name_obj+m));
                ;
                printf("score:%lf\n",allclass_ave(cjj+m));
                a++;
           }
           break;
           //分别统计低于全班各门课程平均成绩的人数；
      case('c'):

            for(h=0;h<M;h++)
           {
            printf("the numbers of student who are lower than the average score of %s ",*(name_obj+h));
            printf("%d\n",low_a(cjj+h,allclass_ave(cjj+h)));
            a++;}
            break;
      case('d'):
          {
              //分别统计全班各门课程不及格的人数和90分以上（含90分）的人数。
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

double ave_s(double *a)// //计算每个学生各门课程平均成绩；
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
