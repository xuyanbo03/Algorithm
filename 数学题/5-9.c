/***********************Procedure Einstein's question*******************************/
#include <string.h> 
#include <stdio.h> 

void main()
{
    int x=7,i,res,flag=0;
    for(i=1;i<=100;i++)                                /*��ѭ��������Ϊ100*/
    {
        if((x%2==1)&&(x%3==2)&&(x%5==4)&&(x%6==5) )  /*���x������Ŀ������Ҫ��*/
        {
            res=x;
            flag=1;
            break;                                      /*����ѭ�������ٽ��бȽ�*/
        }
        x=7*(i+1);
    }
    if(1==flag)
        printf("The result of Einstein's question is %d",res);      /*�����*/
    else
        printf("In this rage cannot get result\n ");             /*�ڳ����޶��ķ�Χ���Ҳ�����*/
}

