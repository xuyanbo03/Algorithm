#include "stdio.h"
void trans(int n)
{
    int i;
    i = n % 10;     /*�õ�����n�ĸ�λ����*/
    if(n/10>0)
    trans(n/10);   /*�ݹ����trans������λ��ת��Ϊ�ַ���*/
    printf("%c",i+48);
}

main()
{
    printf("The translation of 12345 from interger to string\n");
    trans(1235);
    getche();
}
