#include <stdio.h>
#include <stdlib.h>

/*
�ݹ鷴������ַ���

�ַ���������־��#��
�����ַ�����һ���ַ����浽a�У��ݹ����Print������ֱ��������#��
*/

Print()
{
    char a;
    scanf("%c",&a);
    if(a!='#')
        Print();
    if(a!='#')
        printf("%c",a);
}

main()
{
    printf("Please input a string ending for '#'\n");
    Print();
    getche();
}
