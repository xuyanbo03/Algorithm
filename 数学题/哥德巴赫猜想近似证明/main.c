#include <stdio.h>
#include <stdlib.h>

/*
��°ͺղ��룺�Ⱥ�һ������2��ż�����ܱ�ʾ����������֮��

����֤������һ����Χ��

�����жϣ�һ����ż��aһ�����Ա�ʾ��a/2����������ӵ���ʽ��ֻҪ����һ��a=i+j�����ж��������
*/

int isGoldbach(int a);
int TestifyGB_Guess(int low,int high);
int isPrime(int i);

void main()
{
    printf("Now testify Goldbach Guess in the range of 1~100\n\n");//��֤1~100���ڵĸ�°ͺղ���
    if(TestifyGB_Guess(1,100))
        printf("\nIn the range of 1~100,Goldbach Guess is right.\n");
    else
        printf("\nGoldbach Guess is wrong.\n");
    getchar();
}

int TestifyGB_Guess(int low,int high)//��low��high֮����֤��°ͺղ���
{
    int i,j=0;
    int flag=0;
    for(i=low;i<=high;i++)
    {
        if(i%2==0&&i>2)
        {
            if(isGoldbach(i))//ż��i���ϸ�°ͺղ���
            {
                j++;//j���������ʽ
                if(j==10)//���10������
                {
                    printf("\n");
                    j=0;
                }
            }
            else
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
        return 1;//��°ͺղ�����ȷ����1
    else
        return 0;//��°ͺղ��벻��ȷ����0
}

int isGoldbach(int a)//�ж�ż��a�Ƿ���ϲ���
{
    int i,flag=0;
    for(i=1;i<=a/2;i++)
    {
        if(isPrime(i)&&isPrime(a-i))//���i��a-i��Ϊ���������ϲ���
        {
            flag=1;
            printf("%d=%d+%d",a,i,a-i);
            break;
        }
    }
    if(flag==1)
        return 1;//��°ͺղ�����ȷ����1
    else
        return 0;//��°ͺղ��벻��ȷ����0
}

int isPrime(int i)//�ж�i�Ƿ�������
{
    int n,flag=1;
    if(1==i)//1��������
        flag=0;
    for(n=2;n<i;n++)
    {
        if(i%n==0)//����2~i-1֮�����������ӣ���i����������flag��Ϊ0
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
        return 1;//i����������1
    else
        return 0;//i������������0
}
