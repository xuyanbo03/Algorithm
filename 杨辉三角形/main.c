#include <stdio.h>
#include <stdlib.h>

/*
��ӡ���������
����ʽ(a+b)^N��չ��ʽ��ϵ��
��i�е�j�����ݵ�ֵ���ڵ�i-1�еĵ�j-1��j������ֵ֮��
��i�е�j�����ݵ�ֵ������1
��������������

6���������
*/

main()
{
    int i,j,k,buf[7],tmp[7];//N=6ʱ���������������Ϊ7
    for(i=0;i<=6;i++)
    {
        if(i==0)
        {
            printf("%d",1);//��ӡ��һ��
        }
        else if(i==1)
        {
            printf("\n%d %d\n",1,1);//��ӡ�ڶ���
            buf[0]=1;
            buf[1]=1;
        }
        else
        {
            for(j=1;j<=i+1;j++)
            {
                if(j==1||j==i+1)
                {
                    printf("%d ",1);
                    tmp[j-1]=1;
                }
                else
                {
                    printf("%d ",buf[j-2]+buf[j-1]);
                    tmp[j-1]=buf[j-2]+buf[j-1];
                }
            }
            printf("\n");
            for(k=0;k<7;k++)
                buf[k]=tmp[k];//����i�е����ݴ�ŵ�buf[0]~buf[i]��
        }
    }
}
