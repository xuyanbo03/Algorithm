#include <time.h> 
#include <stdio.h> 
#include <dos.h> 
int main() 
{ 
   clock_t start, end;
   /*�������е����ڵ�ʱ��*/
   start = clock(); 
   /*���1��*/
   sleep(1);
   /*�������е����ڵ�ʱ��*/
   end = clock(); 
   printf("The time was: %f\n", (end - start) / CLK_TCK); 
   getche();
   return 0; 
}

