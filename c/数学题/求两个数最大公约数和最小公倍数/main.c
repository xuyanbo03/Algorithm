#include <stdio.h>
#include <stdlib.h>

/*
�������������Լ������С������

���Լ�����������Ĺ�������������һ��
��С���������������Ĺ���������С��һ��
*/

int gcd(int a,int b)
{
    int min;
    if(a<=0||b<=0)
        return -1;
    if(a>b)//����Сֵ
        min=b;
    else
        min=a;
    while (min)
    {
        if(a%min==0&&b%min==0)//�жϹ�����
            return min;//�ҵ��������
        min--;//û�ҵ����Լ�
    }
    return -1;
}

int lcm(int a,int b)
{
    int max;
    if(a<=0||b<=0)
        return -1;
    if(a>b)//�����ֵ
        max=a;
    else
        max=b;
    while (max)
    {
        if(max%a==0&&max%b==0)//�жϹ�����
            return max;//�ҵ�������
        max++;//û�ҵ�������
    }
    return -1;
}

main()
{
    int a,b;
    printf("Please input two digit for getting GCD and LCM\n");
    scanf("%d %d",&a,&b);
    printf("The GCD of %d and %d is %d\n",a,b,gcd(a,b));
    printf("The LCM of %d and %d is %d\n",a,b,lcm(a,b));
    getche();
}
