//用单向链表建立一张班级成绩单，包括每个学生的学号、姓名、英语、高等数学、普通物理、C语言程序设计四门课程的成绩。用函数编程实现下列功能：
//(1) 输入每个学生的各项信息。
//(2) 输出每个学生的各项信息。
//(3) 修改指定学生的指定数据项的内容。
//(4) 统计每个同学的平均成绩（保留2位小数）。
//(5) 输出各位同学的学号、姓名、四门课程的总成绩和平均成绩。

#include<stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct class_score_form)
struct class_score_form
{
    int student_number;
    char name[20];
    double grade_english;
    double grade_maths;
    double grade_physcis;
    double grade_c;
    struct class_score_form *next;
    struct class_score_form *pre;

};
void print(struct class_score_form *head);
void change(struct class_score_form *head);
void change2(struct class_score_form *head,int ,char );
void average(struct class_score_form *head);
void totel(struct class_score_form *head);
void paixu(struct class_score_form *head);
void paixu2(struct class_score_form *head);
int main(void)
{
    struct class_score_form *head;
    struct class_score_form *tail;
    struct class_score_form *p;
    int n=1;
    int a=1;
    head=(struct class_score_form*)malloc(LEN);
    head->next=NULL;
    tail=head;
       do {
               p=(struct class_score_form*)malloc(LEN);
               printf("Please input the information of student %d and input 0 to end.\n",n);
               printf("number:\n"); scanf("%d",&p->student_number);
               if(p->student_number)
                {
               printf("name:\n");  scanf("%s",&p->name);
               printf("score(English,maths,physcis,c):\n");
               scanf("%lf",&p->grade_english);
               scanf("%lf",&p->grade_maths);
               scanf("%lf",&p->grade_physcis);
               scanf("%lf",&p->grade_c);


               p->next=NULL;//结点的指针域为空
               p->pre=tail;//节点的前驱是p
               tail->next=p;//将新结点插入链表尾部
               tail=p;//让链表的尾结点指向新结点


               }printf("\n\n");

        }
        while(p->student_number);

      printf("Please input the number of each fuc：\n");
       printf("\n(1) 输出每个学生的各项信息。\n(2) 修改指定学生的指定数据项的内容。\n(3) 统计每个同学的平均成绩（保留2位小数）\n(4) 输出各位同学的学号、姓名、四门课程的总成绩和平均成绩。\n(5) 按照从低到高排序\n(6) 交换链表方式的排序\n\n");
while(a)
       {scanf("%d",&a);
       switch(a)
       {
   case(1): print(head);break;
   case(2): change(head);break;
   case(3): average(head);break;
   case(4): totel(head);break;
   case(5): paixu(head);break;
   case(6): paixu2(head);break;
       }}


}

void print(struct class_score_form *head)
{
    struct class_score_form *p;
    p=head->next;
    int n=1;

    while(p!=NULL)
    {
        printf("%d.The information of student %d :\n",n,n);
        printf("Student number:%d\n",p->student_number);
        printf("Student name:%s\n",p->name);
        printf("Student score:\nEnglish:%.2lf  Maths:%.2lf  Physcis:%.2lf  C:%.2lf\n\n",p->grade_english,p->grade_maths,p->grade_physcis,p->grade_c);
        p=p->next;n++;
    }
}

void change(struct class_score_form *head)
{
    int  a,b;
    printf("Please input the student number you wanted to change:");
    scanf("%d",&a);getchar();
    printf("if you want to change the number,input 'a'.\n");
    printf("if you want to change the name,input 'b'.\n");
    printf("if you want to change the score of English,input 'c'.\n");
    printf("if you want to change the score of Maths,input 'd'.\n");
    printf("if you want to change the score of Physcis,input 'e.\n");
    printf("if you want to change the score of c,input 'f.\n");
    scanf("%c",&b);

    change2(head,a,b);


}
void change2(struct class_score_form *head,int a,char b)
{
        struct class_score_form *p;
        p=head->next;
        while(p->student_number!=a)
        {
            p=p->next;
        }

        switch(b)
    {
    case 'a': {printf("Please input the correct date:\n "); scanf("%d",&p->student_number);}break;
    case 'b': {printf("Please input the correct date:\n "); scanf("%s",&p->name);}break;
    case 'c':{printf("Please input the correct date:\n "); scanf("%lf",&p->grade_english);}break;
    case 'd':{printf("Please input the correct date:\n "); scanf("%lf",&p->grade_maths);}break;
    case 'e':{printf("Please input the correct date:\n "); scanf("%lf",&p->grade_physcis);}break;
    case 'f':{printf("Please input the correct date:\n "); scanf("%lf",&p->grade_c);}break;

    }
  printf("OK.the data is changed,you can input 1 to check it.\n");
}

void average(struct class_score_form *head)
{
    double sum,ave;
    int n=1;
    struct class_score_form *p;
    p=head->next;
    while(p!=NULL)
    {
        sum=(p->grade_english)+(p->grade_maths)+(p->grade_physcis)+(p->grade_c);
        ave=sum/4.0;
        printf("%d.the average score of student %s is %.2lf.\n",n,p->name,ave);
        p=p->next;
    }

}

void totel(struct class_score_form *head)
{
    double sum,ave;
        struct class_score_form *p;
    p=head->next;
    int n=1;

    while(p!=NULL)
    {
        sum=(p->grade_english)+(p->grade_maths)+(p->grade_physcis)+(p->grade_c);
        ave=sum/4.0;
        printf("%d.The information of student %d :\n",n,n);
        printf("Student number:%d\n",p->student_number);
        printf("Student name:%s\n",p->name);
        printf("Student score:\nEnglish:%.2lf  Maths:%.2lf  Physcis:%.2lf  C:%.2lf\n",p->grade_english,p->grade_maths,p->grade_physcis,p->grade_c);
        printf("average:%.2lf,sum:%.2lf\n\n",ave,sum);
        p=p->next;n++;
    }
}

void paixu(struct class_score_form *head)
{
    double a,b;
    double t[4];
    char k[20];
    int h;
     struct class_score_form *p,*pp,*stu_1,*stu_2;
     pp=head;
     p=pp->next;
     for(stu_1=p;stu_1!=NULL; stu_1=stu_1->next)
        for(stu_2=p; stu_2!=NULL;stu_2=stu_2->next)
        {
            a=(stu_1->grade_english)+(stu_1->grade_maths)+(stu_1->grade_physcis)+(stu_1->grade_c);
            b=(stu_2->grade_english)+(stu_2->grade_maths)+(stu_2->grade_physcis)+(stu_2->grade_c);
            printf("%d %d",a,b);
            if(a>b)
            {
                h=stu_2->student_number;
                *k=*stu_2->name;
                t[0]=stu_2->grade_english;
                t[1]=stu_2->grade_maths;
                t[2]=stu_2->grade_physcis;
                t[3]=stu_2->grade_c;

                stu_2->student_number= stu_1->student_number;
                *stu_2->name=*stu_1->name;
                stu_2->grade_english=stu_1->grade_english;
                stu_2->grade_maths=stu_1->grade_maths;
                stu_2->grade_physcis=stu_1->grade_physcis;
                stu_2->grade_c=stu_1->grade_c;

                stu_1->student_number=h;
                *stu_1->name=*k;
                stu_1->grade_english=t[0];
                stu_1->grade_maths=t[1];
                stu_1->grade_physcis=t[2];
                stu_1->grade_c=t[3];
            }
        }
        print(pp);

}
void paixu2(struct class_score_form *head)
{
       double a,b;
     struct class_score_form *pp,*stu_1,*stu_2,*k;
      struct class_score_form *prior1,*prior2;
        struct class_score_form *next1,*next2;
     pp=head;

     for(prior1=pp,stu_1=prior1->next,next1=stu_1->next;stu_1->next!=NULL; prior1=stu_1,stu_1=stu_1->next,next1=stu_1->next)
     {
          for(stu_2=stu_1->next,prior2=stu_1; stu_2->next!=NULL; prior2=stu_2,stu_2=stu_2->next)
      {
            if(stu_2->next!=NULL) next2=stu_2->next;
            a=(stu_1->grade_english)+(stu_1->grade_maths)+(stu_1->grade_physcis)+(stu_1->grade_c);
            b=(stu_2->grade_english)+(stu_2->grade_maths)+(stu_2->grade_physcis)+(stu_2->grade_c);
           //printf("%lf \n%lf \n\n",a,b);
            if(a>b)
            {

                prior1->next=stu_2;
                next1->pre=stu_2;
                stu_2->pre=prior1;
                stu_2->next=next1;

                prior2->next=stu_1;
                stu_1->pre=prior2;

                if(next2!=NULL)
                {stu_1->next=next2;
                 next2->pre=stu_1;}
                 else
                 {
                     stu_1->next=NULL;
                 }

                k=stu_1;
                 stu_1=stu_2;
                stu_2=k;
            }

     } printf("\n\n");
     }

      print(pp);
}


/*
    3
    c
    120
    120
    120
    120
    1
    a
     123 123 123 123
    2
    b
    23 23 23 23

    4
    d
    56 6 5 6
    5
    f
   189 189 189 189
    0


*/
