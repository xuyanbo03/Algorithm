#include <stdio.h>
#include <stdlib.h>

/*
哥德巴赫猜想：热河一个大于2的偶数都能表示成两个素数之和

近似证明：在一定范围内

素数判断：一个正偶数a一定可以表示成a/2种正整数相加的形式，只要存在一种a=i+j，可判定满足猜想
*/

int isGoldbach(int a);
int TestifyGB_Guess(int low,int high);
int isPrime(int i);

void main()
{
    printf("Now testify Goldbach Guess in the range of 1~100\n\n");//验证1~100以内的哥德巴赫猜想
    if(TestifyGB_Guess(1,100))
        printf("\nIn the range of 1~100,Goldbach Guess is right.\n");
    else
        printf("\nGoldbach Guess is wrong.\n");
    getchar();
}

int TestifyGB_Guess(int low,int high)//在low和high之间验证哥德巴赫猜想
{
    int i,j=0;
    int flag=0;
    for(i=low;i<=high;i++)
    {
        if(i%2==0&&i>2)
        {
            if(isGoldbach(i))//偶数i符合哥德巴赫猜想
            {
                j++;//j控制输出格式
                if(j==10)//输出10组运算
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
        return 1;//哥德巴赫猜想正确返回1
    else
        return 0;//哥德巴赫猜想不正确返回0
}

int isGoldbach(int a)//判断偶数a是否符合猜想
{
    int i,flag=0;
    for(i=1;i<=a/2;i++)
    {
        if(isPrime(i)&&isPrime(a-i))//如果i和a-i都为素数，符合猜想
        {
            flag=1;
            printf("%d=%d+%d",a,i,a-i);
            break;
        }
    }
    if(flag==1)
        return 1;//哥德巴赫猜想正确返回1
    else
        return 0;//哥德巴赫猜想不正确返回0
}

int isPrime(int i)//判断i是否是素数
{
    int n,flag=1;
    if(1==i)//1不是素数
        flag=0;
    for(n=2;n<i;n++)
    {
        if(i%n==0)//若在2~i-1之间有其他银子，则i不是素数，flag置为0
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
        return 1;//i是素数返回1
    else
        return 0;//i不是素数返回0
}
