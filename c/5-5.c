/***********************Procedure BQBJ*******************************/
#include <string.h> 
#include <stdio.h> 

int accord(int i,int j,int k) ;

void main()
{
    int i,j,k;
    printf("The possible plans for buying 100 fowls with 100 yuan are:\n\n");
    for(i=0;i<=100;i++)
        for(j=0;j<=100;j++)
            for(k=0;k<=100;k++)
                if(accord(i,j,k))
                    printf("cock=%d,hen=%d,chicken=%d\n",i,j,k);
    getchar();
}

int accord(int i,int j,int k)
{
    if(5*i+3*j+k/3==100&&k%3==0&&i+j+k==100)      /*��Ȼk��Ϊ3��������*/
        return 1;                              /*���ϰ�ǧ�ټ�Ҫ�󷵻�1*/

    else
        return 0;                              /*�����ϰ�ǧ�ټ�Ҫ�󷵻�0*/
}
