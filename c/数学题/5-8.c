#include "stdio.h"

main()
{
    char husband[3] = {'A','B','C'}, wife[3] = {'X','Y','Z'};
    int i ,j ,k;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            for(k=0;k<3;k++)
                if(i!=j && j!=k && i!=k) /*����1��������2������*/
                {
                    /*�õ�һ����Է�ʽ*/
                    if (match(i,j,k,wife))
                    {
                        printf("husband  wife\n");
                        /*������Է�ʽ������ĿҪ��*/
                        printf("A---------%c\n",wife[i]);
                        printf("B---------%c\n",wife[j]);
                        printf("C---------%c\n",wife[k]);
                    }
                }

                getche();
}

int match(int i,int j,int k,char wife[])
{
    /*A����X���*/
    if(wife[i] == 'X') return 0;
    /*X����C���*/
    if(wife[k] == 'X') return 0;
    /*C����Z���*/
    if(wife[k] == 'Z') return 0;
    return 1;
}

