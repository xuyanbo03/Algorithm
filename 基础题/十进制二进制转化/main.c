#include <stdio.h>
#include <stdlib.h>

/*ʮ����/������ת��
��2ȡ��
����ʵ��
*/

deTobi(int a)
{
    int i=0,stack[10],r,s;
    do{
        r=a/2;/*��*/
        s=a%2;/*����*/
        stack[i]=s;/*��s��ջstack����*/
        if(r!=0)
        {
            i++;
            a=r;/*��a����2�Ľ����Ϊ��һ������2�Ķ���*/
        }
    }while(r);/*ѭ��ֱ����rΪ0Ϊֹ*/
    for(;i>=0;i--)
        printf("%d",stack[i]);/*��ӡ������*/
    printf("\n");
}

int main()
{
    int a;
    printf("Please input a Decimal digit\n");
    scanf("%d",&a);
    deTobi(a);
    getchar();
    return 0;
}
