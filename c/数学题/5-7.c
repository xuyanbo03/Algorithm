#include "stdio.h"
int reverse(i)
{
    /*��i�ĵ�����*/
    int r = 0;
    while(i)
    {
        r = r * 10 + i % 10;
        i = i /10;
    }
    return r;
}

int fun(int i, int j)
{
    /*�ж�ABCDE 5�������Ƿ���ͬ*/
    int buf[4] , k = 0;
    while(i){
        buf[k] = i % 10;
        i = i / 10;
        k++;
    }
    if(buf[0] == buf[1]) return 0;   /* A��B�Ƚ� */
    if(buf[0] == buf[2]) return 0;   /* A��C�Ƚ� */
    if(buf[0] == buf[3]) return 0;   /* A��D�Ƚ� */
    if(buf[0] == j)      return 0;  /* A��E�Ƚ� */
    if(buf[1] == buf[2]) return 0;   /* B��C�Ƚ� */
    if(buf[1] == buf[3]) return 0;   /* B��D�Ƚ� */
    if(buf[1] == j)      return 0;  /* B��E�Ƚ� */
    if(buf[2] == buf[3]) return 0;   /* C��D�Ƚ� */
    if(buf[2] == j)      return 0;  /* C��E�Ƚ� */
    if(buf[3] == j)      return 0;  /* D��E�Ƚ� */
    return 1;
    
}

main()
{
    int i,j;
    for(i=1000;i<10000;i++)                 /*����4λ���ռ�[1000��9999]*/
        for(j=1;j<10;j++)                    /*����1λ���ռ�[1��10]*/
            if(i * j == reverse(i) && fun(i,j))       /*���i,j������Ŀ��Ҫ��*/
               {
                printf("%d\n",i);
                printf("*  %d\n",j);
                printf("----------\n");
                printf("%d\n\n",i*j);  
         }
}

