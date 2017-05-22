#include "stdio.h"

void reverse(char *str,int i)
{
    int j=0;
    char tmp;
    while(j<i-j-1)
    {
        tmp = str[j];
        str[j] = str[i-j-1];
        str[i-j-1] = tmp;
        j++;
    }
}

void myitoa(int n ,char *str)
{
    char a;
    int i=0;
    while(n!=0)
    {
        a = n % 10;
        a = a + 48;
        str[i] = a;
        i++;
        n = n / 10;
    }
    /*iΪ�ַ����ĳ���*/
    reverse(str,i); /*���ú���str���ַ�������*/
    str[i] = '\0';
}

main()
{
    int n = 1263;				/*��������n=1263*/
    char str[5];					/*�����ַ����飬�������n���ַ���*/
    myitoa(n,str);				/*������nת��Ϊ��Ӧ���ַ���str*/
    printf("The integer is %d\n",n);	/*��ӡ������n*/
    printf("The string of this integer is %s\n",str);	/*��ӡ��ת������ַ���str*/
    getche();
}
