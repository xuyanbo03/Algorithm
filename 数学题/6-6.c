#include "stdio.h"

int getMin(int array[],int n)
{
    int val1,val2,val3;
    if(n == 1) return array[0];
    if(n%2 == 0)
    {
        val1 = getMin(array, n/2);
        val2 = getMin(array+n/2, n/2);
        if(val1<val2)
            return val1;
        else
            return val2;
    }
    if(n%2 != 0)
    {
        val1 = getMin(array, n/2);
        val2 = getMin(array+n/2+1,n/2);
        val3 = array[n/2];
        if(val1<val2)
    	{
            if(val1<val3) return val1;
            else return val3;
    	}
        else
    	{
            if(val2<val3) return val2;
            else return val3;
    	}
    }
}

main()
{
    int array[9]={11,13,23,56,8,23,11,23,111},val; 	/*���Ե����飬����Ԫ��8Ϊ��Сֵ*/
    val = getMin(array,9);						/*���õݹ麯��getMin�����Сֵ*/
    printf("%d",val);
    printf("The minum element of this array is %d \n",val);
}
