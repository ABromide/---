#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char ch;
	int i=0;
	FILE *fp;
	char str[200];
	char *p=str;

	fp=fopen("12345.txt","w");
	fgets(str,199,stdin);
	str[0]=str[0]+'A'-'a';
	 while(str[i++]!='\0')
     {
         if(str[i]==' ') ;
         else if(str[i]!=' '&&str[i-1]==' ') str[i]=str[i]+'A'-'a';
         else if((str[i-1]<'a'&&str[i-1]>'z')&&(str[i-2]>='a'&&str[i-2]<='z'))
            str[i]=str[i]+'A'-'a';
         else;
     }
     fputs(str,fp);
     puts(str);
     fclose(fp);

 return 0;
}
//sentences from the keyboard，replace the first letter
