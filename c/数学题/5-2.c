#include "stdio.h"
int gcd(int a,int b){
    /*���Լ��*/
    int min;
    if(a<=0||b<=0) return -1;
    if(a>b) min = b;                       /*�ҵ�a,b�еĽ�С��һ����ֵ��min*/
    else min = a;
    while(min){
    if(a%min == 0 && b%min == 0)       /*�жϹ�����*/
    return min;                    /*�ҵ����Լ��,����*/
    min--;                              /*û���ҵ����Լ��,min��1*/
    }
    return -1;
}

int lcm(int a,int b){
    /*��С������*/
    int max;
    if(a<=0||b<=0) return -1;
    if(a>b) max = a;
    else max = b;      /*�ҵ�a,b�еĽϴ��һ����ֵ��max*/
    while(max){
    if(max%a == 0 && max%b == 0)       /*�жϹ�����*/
    return max;                  /*�ҵ���С������,����*/
    max++;                            /*û���ҵ���С������,max��1*/
    }
    return -1;
}

main()
{
    int a,b;
    printf("Please input two digit for getting GCD and LCM\n");
    scanf("%d %d",&a,&b);         
    printf("The GCD of %d and %d is %d\n",a,b,gcd(a,b));       /*��ӡ��a,b�����Լ��*/
    printf("The LCM of %d and %d is %d\n",a,b,lcm(a,b));       /*��ӡ��a,b����С������*/
    getche();
}

