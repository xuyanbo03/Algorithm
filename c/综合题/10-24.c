#include "stdio.h"

int latterNumber(char *str)
{
    int i,count=0,flag ;
    char *p = str;
    while(*p != '\0')
    {
        if((*p>='A'&&*p<='Z')||(*p>='a'&&*p<='z') ) /*����ĸ*/
            flag = 1;
        else
        {
            flag++;
        }
        if(flag == 2)
            count++;
        p++;
    }
    return count;
}

main()
{
    char str[] = "This  is  a test!!  ";		/*��ʼ���ַ���*/
    printf("\n%s\n",str);						/*��ʾԭ�ַ���*/
    printf("This string contains %d latter.\n",latterNumber(str));		/*����䵥�ʸ���*/
    getche();
}
