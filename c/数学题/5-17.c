#include "stdio.h"
int match(int i,int j,int k,int l,int m,int n,int o,int p,int q)
{
    /*�жϱ���i-q�Ƿ񻥲����,���򷵻�1,�����򷵻�0*/
    if(i!=j&&i!=k&&i!=l&&i!=m&&i!=n&&i!=o&&i!=p&&i!=q
         &&j!=k&&j!=l&&j!=m&&j!=n&&j!=o&&j!=p&&j!=q
            &&k!=l&&k!=m&&k!=n&&k!=o&&k!=p&&i!=q
                    &&l!=m&&l!=n&&l!=o&&l!=p&&l!=q
                     &&m!=n&&m!=o&&m!=p&&m!=q
                              &&n!=o&&n!=p&&n!=q
                                     &&o!=p&&o!=q
                                          &&p!=q)
    return 1 ;
    else return 0;
}


int justic(int i,int j,int k,int l,int m,int n,int o,int p,int q)
{
    /*�жϱ���i-q�����������Ƿ�����ħ�÷����Ҫ��,���㷵��1,�����㷵��0*/
    if(i+j+k == l+m+n && i+j+k == o+p+q &&
    i+l+o == j+m+p && i+l+o == k+n+q
    && i+m+q == k+m+o)return 1;
    else return 0;
}

void getMatrix(){
    int i,j,k,l,m,n,o,p,q;
    for(i=1;i<=9;i++)
        for(j=1;j<=9;j++)
            for(k=1;k<=9;k++)
                for(l=1;l<=9;l++)
                    for(m=1;m<=9;m++)
                        for(n=1;n<=9;n++)
                            for(o=1;o<=9;o++)
                                for(p=1;p<=9;p++)
                                     for(q=1;q<=9;q++)
                                     {
                                        if(match(i,j,k,l,m,n,o,p,q))
                                        if(justic(i,j,k,l,m,n,o,p,q))
                                        {
                                            printf("%d %d %d\n",i,j,k);  /*������*/
                                            printf("%d %d %d\n",l,m,n);
                                            printf("%d %d %d\n",o,p,q);
                                            printf("\n");
                                            return;
                                        }                                /*����*/
                                     }

}
main()
{
    getMatrix() ; /*���һ������ħ�÷���*/
    getche();
}

