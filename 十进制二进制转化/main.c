#include <stdio.h>
#include <stdlib.h>

/*十进制/二进制转化
除2取余
数组实现
*/

deTobi(int a)
{
    int i=0,stack[10],r,s;
    do{
        r=a/2;/*商*/
        s=a%2;/*余数*/
        stack[i]=s;/*将s入栈stack保存*/
        if(r!=0)
        {
            i++;
            a=r;/*将a整除2的结果作为下一个整除2的对象*/
        }
    }while(r);/*循环直到商r为0为止*/
    for(;i>=0;i--)
        printf("%d",stack[i]);/*打印二进制*/
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
