#include "stdio.h"

void Nicoqish(int N)
{
    int i,j,sum = 0;
    for(i=1;i<N*N*N;i=i+2) 		/*iΪ���*/
        for(j=i;j<N*N*N;j=j+2) 		/*j���ƴ�i���˳���ۼ�*/
        {
          sum = sum + j;
          if(sum == N*N*N)
          {
            printf("%d=%d+%d...+%d\n",N*N*N,i,i+2,j);
            return;
          }
          if(sum>N*N*N)
          {
             sum = 0;
             break;
          }
        }
}

main()
{
    int N;
    printf("Please input a integer to verify Nicoqish Law\n");
    scanf("%d",&N);
    Nicoqish(N);
    getche();
}
