#include "stdio.h"

char fruit[][10]={"apple","orange","banana","pineapple","pear"};
int fruitPlate()
{
    int x,y,z,count=0;
    for(x=1;x<=5;x++)
        for(y=1;y<=5;y++)
            for(z=1;z<=5;z++)
            {
                if(x!=y && y!=z && x!=z)
                {
                    count++;     /*����*/
                    printf("%9s,%9s,%9s\n",fruit[x-1],fruit[y-1],fruit[z-1]);	/*���ÿһ�ֽ��*/
                }
            }
    return count;		/*����ƴ�̵�������*/
}
main()
{
    printf("There are %d kinds of motheds for arranging plate.\n",fruitPlate()) ;
    getche();
}
