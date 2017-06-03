#include "stdio.h"

float func(float x,float y)
{
    return y - 2*x / y;
}

float getResult(float x0,float y0,float h,float xn)
{
    float yp,yc;
    while(x0<xn)
    {
        yp = y0 + h*func(x0,y0);
        yc = y0 + h*func(x0+h,yp);
        y0 = 1.0/2.0*(yp + yc);
        x0 = x0 + h;
    }
    return y0;
}

main()
{
    float x0,y0,h,xn;
    printf("Please input the initial value x0 & y0\n");        /*�����ʼֵx0��y0*/
    scanf("%f %f",&x0,&y0);
    printf("Please input the step length\n");            /*���벽��ֵh*/
    scanf("%f",&h);
    printf("Please input Xn\n");                        /*����Ҫ���y(xn)��xn*/
    scanf("%f",&xn);
    printf("The result of the function is %f\n",getResult(x0,y0,h,xn));
    getche();
}

