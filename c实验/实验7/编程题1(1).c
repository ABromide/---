/*��1�����һ���ֶνṹstruct bits������һ��8λ�޷����ֽڴ����λ�����λ����Ϊ8���ֶΣ�
���ֶ�����Ϊbit0, bit1, ��, bit7����bit0�����ȼ���ߡ�ͬʱ���8����������i��������biti(i=0,1,2,��,7)
Ϊ�����������ں����������biti��ֵ����8�����������ִ���һ������ָ������p_fun�����bit0Ϊ1��
����p_fun[0]ָ��ĺ��������struct bits���ж�λΪ1����������ȼ��Ӹߵ������ε��ú���ָ��
����p_fun����ӦԪ��ָ��ĺ�����8�������еĵ�0�������������Ϊ��
		void f0(struct bits b)
{
	Printf(��the function %d is called!\n��,b);
}
*/
#include "stdio.h"
#include "stdlib.h"
struct bits
{
    unsigned short int  bit0:1;
    unsigned short int  bit1:1;
    unsigned short int  bit2:1;
    unsigned short int  bit3:1;
    unsigned short int  bit4:1;
    unsigned short int  bit5:1;
    unsigned short int  bit6:1;
    unsigned short int  bit7:1;
};
void f0(struct bits b);
void f1(struct bits b);
void f2(struct bits b);
void f3(struct bits b);
void f4(struct bits b);
void f5(struct bits b);
void f6(struct bits b);
void f7(struct bits b);



int main(void)
{
    int i=0;
    struct bits simple1={1,0,0,1,1,0,1,1};
    struct bits *p=&simple1;
    void (*p_fun[8])(unsigned short int);
    p_fun[0]=f0;
    p_fun[1]=f1;
    p_fun[2]=f2;
    p_fun[3]=f3;
    p_fun[4]=f4;
    p_fun[5]=f5;
    p_fun[6]=f6;
    p_fun[7]=f7;

        if(p->bit0)  p_fun[0](p->bit0);
        if(p->bit1)  p_fun[1](p->bit1);
        if(p->bit2)  p_fun[2](p->bit2);
        if(p->bit3)  p_fun[3](p->bit3);
        if(p->bit4)  p_fun[4](p->bit4);
        if(p->bit5)  p_fun[5](p->bit5);
        if(p->bit6)  p_fun[6](p->bit6);
        if(p->bit7)  p_fun[7](p->bit7);


    return 0;
}


void f0(struct bits b)
{
	printf("0the function %d is called!\n",b);
}
void f1(struct bits b)
{
	printf("1the function %d is called!\n",b);
}
void f2(struct bits b)
{
	printf("2the function %d is called!\n",b);
}
void f3(struct bits b)
{
	printf("3the function %d is called!\n",b);
}
void f4(struct bits b)
{
	printf("4the function %d is called!\n",b);
}
void f5(struct bits b)
{
	printf("5the function %d is called!\n",b);
}
void f6(struct bits b)
{
	printf("6the function %d is called!\n",b);
}
void f7(struct bits b)
{
	printf("7the function %d is called!\n",b);
}
