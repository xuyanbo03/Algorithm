#include "stdio.h"
void delChar(char *str,char c)
{
    char *q , *p = str;
    while(*p!='\0')
    {
        if(*p == c)
        {
           q = p;
           do{
                *q = *(q+1);
                q++;
           }
           while(*q != '\0') ;
        }
        p++;
    }
}

main()
{
    char str[] = "abcdefdhidkldn";				/*��ʼ���ַ���*/
    char c;
    printf("Input the charactor for deleting\n");
    scanf("%c",&c);							/*�û�ָ��Ҫɾ�����ַ�*/
    printf("The string before deleting: %s\n",str);	/*���ԭ�ַ���������*/
    delChar(str,c);							/*ɾ��ָ�����ַ�*/
    printf("The string after deleting: %s\n",str);		/*����������ַ���*/
    getche();
}
