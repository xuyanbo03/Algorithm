#include "stdio.h"
main()
{
   int computer , people , spare = 21;
      printf(" -----------------------------------------\n");
      printf(" --------  �㲻��սʤ��,��������  --------\n");
      printf(" -----------------------------------------\n\n");
      printf("Game begin:\n\n");
   while(1)
   {
        printf(" ----------  Ŀǰ���л�� %d �� ----------\n",spare);
        printf("People:") ;
        scanf("%d",&people);
        if(people<1 || people>4 || people>spare)
        {printf("��Υ���ˣ���ȡ�Ļ����������!\n\n");continue;}
        spare = spare - people;
        if(spare == 0){printf("\nComputer win! Game Over!\n"); break;}
        computer =  5 - people;
        spare = spare - computer;
        printf("Computer:%d  \n",computer);
        if(spare == 0){printf("\nPeople win! Game Over!\n"); break;}
   }
}

