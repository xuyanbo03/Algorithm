#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
�Ẻ����ʧ��

��i������2^(i-1)��
*/

main()
{
    double sum=0;//����˫���ȱ����洢����
    int i;
    for(i=1;i<=64;i++)
        sum=sum+pow(2,i-1);//�ۼ����
    printf("The number of the grain is \n%f\n",sum);
}
