#include "stdio.h"
#include "math.h"

/*
������:������������
*/

double SQRT(double a){                /*��������������*/
    double xx = a,x = 0.0;             /*������ֵ*/
    while(fabs(xx - x)>0.00001){
        x = xx;
        xx = 0.5*(x + a / x) ;
    }
    return xx;                        /*���ص������*/
}

main()
{
    double a,r;
    printf("Please input a digit for squart\n");
    scanf("%lf",&a);
    r = SQRT(a);
    printf("Sqrt(%f) = %f\n",a,r);
    getche();
}

