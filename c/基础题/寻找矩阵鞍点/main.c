#include <stdio.h>
#include <stdlib.h>

/*
һ�������У��ڸ�������ڸ�����С����Ϊ���㡣
һ������Ҳ����û�а��㡣������һ�����㡣
��������5X5�����Ұ��㣬������ھ����λ�ã��С��У�

����Ѱ�Ұ���
����ĳ������Ԫ�أ��ٽ���Ԫ����ͬ��Ԫ�رȽ���С
*/

int getSaddlePoint(int *x,int *y,int (*A)[5],int m,int n)
{
    int max,i,j,k,flag;
    for(i=0;i<m;i++)//����ɨ��Ѱ�Ұ���
    {
        max=0;//max��¼��i�������ֵ������
        flag=1;
        for(j=1;j<n;j++)//�ҳ���i�������Ԫ�ص�λ��A[i][max]
        {
            if(A[i][j]>A[i][max])
                max=j;
        }
        for(k=0;k<n;k++)
        {
            if(A[max]==A[i][k]&&max!=k)//����������Ԫ��A[i][max]��ֵ��ȣ�û�а���
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            for(k=0;k<m;k++)//�ж�A[i][max]�Ƿ��Ǳ�������С��
            {
                if(A[k][max]<=A[i][max]&&k!=i)//������СԪ�أ����ǰ���
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1)//�ҵ����㣬��*x,*y���أ��������
        {
            *x=i;//��
            *y=max;//��
            return 1;
        }
    }
    return 0;//û���ҵ�����
}

main()
{
    int A[5][5],i,j,x,y;
    printf("Please input some digit into the 5X5 matrix\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&A[i][j]);//�������
        }
    }
    if(getSaddlePoint(&x,&y,A,5,5))
    {
        printf("\nSaddlePoint is at (%d,%d)",x+1,y+1);
    }
    else
    {
        printf("\nThere is no in the matrix\n");
    }
    getchar();
}
