#include "stdio.h"

int getAge(int n)
{
    if(n == 1) return 10;           /*��һ����ʮ��*/
    else    return getAge(n-1)+2;    /*��n���˵�����ȵ�n-1�˵������2��*/
}

main()
{
    printf("Age of the first  person is %d\n",getAge(1));
    printf("Age of the second person is %d\n",getAge(2));
    printf("Age of the third  person is %d\n",getAge(3));
    printf("Age of the forth  person is %d\n",getAge(4));
    printf("Age of the fifth  person is %d\n",getAge(5));
    getche();
}
