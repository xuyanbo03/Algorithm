#include "stdio.h"
unsigned long myPow(int m,int n)
{
  unsigned long tmp;
  if(n == 0) return 1;
  if(n == 1) return m;
  if(n % 2 == 0){
    tmp = myPow(m,n/2);
    return tmp * tmp;
    }
  if(n % 2 != 0)
    return m * myPow(m,n-1);
}

main()
{
    int m,n;
    printf("Please input the bottom number\n");
    scanf("%d",&m);							/*�������m*/
    printf("Please input the exponent number\n");
    scanf("%d",&n);							/*����ָ��n*/
    printf("The result of power(m,n) is %ld\n",myPow(m,n));		/*���������mn*/
    getche();
}
