#include "stdio.h"
#include "string.h"
#define CHANGE 0
int main(void)
{
	char a[50],b[50];
	int t=0;

    fgets(a,50,stdin);
	#if CHANGE==1
        printf("%s\n",a);
    #else
        for(t=0;t<strlen(a);t++)
		 {
		if (a[t]>='A'&&a[t]<='Z') b[t]=a[t]-'A'+'a';
	    else	if (a[t]>='a'&&a[t]<='z') b[t]=a[t]-'a'+'A';
		else b[t]=a[t];
		}
        printf("%s\n",b);
    #endif

    return 0;
	
}
