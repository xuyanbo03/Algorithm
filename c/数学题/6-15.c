#include <stdio.h>
move(int n,char x,char y,char z)
{
    if(n==1)
      printf("%c-->%c\n",x,z);
    else
    {
      move(n-1,x,z,y);
      printf("%c-->%c\n",x,z);
      move(n-1,y,x,z);
    }
}
int main(void) 
{ 
    int n;
    printf("input diskes number:\n");
    scanf("%d",&n);                        /*����������Ŀn*/
    printf("The step to moving %d diskes:\n",n);
    move(n,'A','B','C');                    /*�ݹ����move��������ӵİ��˹���*/
    getche();
    return 0;
}

