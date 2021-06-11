#include "stdio.h"
#include "math.h"
#define AREA(a,b,c,s) sqrt((s)*((s)-(a))*((s)-(b))*((s)-(c)))
#define S(a,b,c) (((a)+(b)+(c))/2)
int main(void)
{
	double a,b,c;
	double s,S;
	scanf("%lf %lf %lf",&a,&b,&c);
	if(a+b<=c||b+c<=a||c+a<=b) printf("error."); 
else{
    s=S(a,b,c);
	printf("s=%lf,area=%lf",s,AREA(a,b,c,s)) ;
	return 0;
	}
}

 
