#include "stdio.h"

int isint(float x)			/*�ж�x�Ƿ�������������Ƿ���1�����򷵻�0*/
{
    if(x-(int) x == 0)
        return 1;
     else
        return 0;
}

func()
{
    float y,x;
    for(y=1;y<=6;y++)
    {
        x = 303*35/(28-5*y);
        if(isint(x))        /*���x������*/
        {
            printf("The amount of stamps are %d\n",(int)x);
            printf("The stamp album 1: %d\n",(int)x/5);
            printf("The stamp album 2: %d\n",(int)x*(int)y/7);
            printf("The stamp album 3: %d\n",303);
        }
    }
}

main()
{
    func();
    getche();
}
