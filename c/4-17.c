#include "stdio.h"
int getSaddlePoint (int *x,int *y,int (*A)[5],int m,int n)
{
    int max , i, j , k ,flag;
    for(i=0;i<m;i++) {            /*����ɨ��Ѱ�Ұ���*/
        max = 0;                    /*max��¼��i�������ֵ������*/
        flag = 1;
        for(j=1;j<n;j++)            /*�ҳ���i���е����Ԫ�ص�λ��A[i][max]*/
        {
           if(A[i][j]>A[i][max]) max = j;
        }
        for(k=0;k<n;k++)
           if(A[i][max] == A[i][k] && max != k){flag = 0;break;}
        if(flag == 1)
        for(k=0;k<m;k++)                /*�ж�A[i][max]�Ƿ��Ǳ�������С��*/
        {
          if(A[k][max]<=A[i][max] && k!=i)  /*������СԪ�أ����A[i][max]���ǰ���*/
          {
            flag = 0;
            break;
          }
        }
        if(flag == 1)                /*�ҵ����㣬��x,y���أ������������1*/
        {
            *x = i;
            *y = max;
            return 1;
        }
       }

       return 0;             /*û���ҵ����㣬����0*/

}

main()
{
    int A[5][5],i,j,x,y;
    printf("Please input some digit into the 5*5 matrix\n");
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
        scanf("%d",&A[i][j]);
    if(getSaddlePoint (&x,&y,A,5,5))
        printf("\nSaddlePoint is at (%d,%d)",x+1,y+1);
    else
        printf("\nThere is no in the matrix\n");
       getche();
}

