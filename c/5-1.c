#include <stdio.h >
#include "math.h"
main()
{
    double sum = 0;  /*����˫���ȱ���sum��Ž��*/
    int i;
    for(i=1;i<=64;i++)
    sum = sum + pow(2,i-1);    /*�ۼ����*/
    printf("The number of the grain is \n%f\n",sum);  /*��ӡ�����*/
}

