#include <stdio.h>
#include <stdlib.h>

/*
����(1/2)^n*n!��ǰ10���S10
ע�⣺�������͵�ѡȡ��ȡ������float
*/

main()
{
    float m=1.0;//��¼(1/2)^n
    float n=1.0;//��¼n��
    float s=0.0;
    int i,j;//ǰ10���
    for(i=1;i<=10;i++)//�����ѭ�������Ƽӷ�����
    {
        for(j=0;j<i;j++)
        {
            m=m*0.5;//����(1/2)^n
        }
        for(j=1;j<=i;j++)
        {
            n=n*j;//����n��
        }
        s=s+m*n;//�ۼ�
        m=1.0;//����
        n=1.0;
    }
    printf("Sn = %f\n",s);//��ӡ���
    getchar();
}
