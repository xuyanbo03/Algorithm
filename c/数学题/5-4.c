#include "stdio.h"
/*��ɫ���������*/
main()
{
    int red,yellow,green;
    printf("red  yellow  green\n");
    for(red=0;red<=3;red++)                         /*��ɫ��0��1��2��3*/
        for(yellow=0;yellow<=3;yellow++)               /*��ɫ��0��1��2��3*/
            for(green=2;green<=6;green++)        /*��ɫ��2��3��4��5��6*/
                if(red+yellow+green == 8)
                    printf("%d      %d      %d\n",red,yellow,green);
}

