#include <stdio.h>
#include <stdlib.h>

/*
���������̶�������

��ٷ�
С��n���Ӵ��ۼӣ��Ӵ����ܷ����ص�
������������ù̶���㣬ɨ������Ԫ�صķ����������������̶��͵�����
*/

void cntnsIntSum(int n)
{
    int i,sum=0,j;
    for(i=1;i<n;i++)//��������ѡ�񣬴�1��n-1
    {
        j=i-1;
        while(sum<n)//��������˳���ۼ�
        {
            j++;//�����ۼӵ�������
            sum=sum+j;//���
        }
        if(sum==n)
        {
            printf("%d+...+%d=%d\n",i,j,n);
        }
        sum=0;
    }
}

main()
{
    int n;
    printf("Please input a integer\n");
    scanf("%d",&n);
    cntnsIntSum(n);
    getche();
}
