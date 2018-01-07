#include <stdio.h>
#include <stdlib.h>

/*
三色球问题：12选8

排列组合
穷举法
*/

main()
{
    int red,yellow,green;
    printf("red  yellow  green\n");
    for(red=0;red<=3;red++)//red:0,1,2,3
    {
        for(yellow=0;yellow<=3;yellow++)//yellow:0,1,2,3
        {
            for(green=2;green<=6;green++)//green:2,3,4,5,6
            {
                if(red+yellow+green==8)
                {
                    printf("%d  %d  %d\n",red,yellow,green);
                }
            }
        }
    }
}
