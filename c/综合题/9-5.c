#include <string.h> 
#include <stdio.h> 
int count=0; /*����������������¼�˻ʺ�����Ľ�ĸ���������һ��ȫ�ֱ���*/

/***************************************************/
/*notEqual����ΪEightQueen����������  */
/*Ŀ���������ж����̵ĵ�row�е�j���ܷ�*/
/*�ڷ�һ���ʺ�����ܹ��ڷŷ���1����  */
/*�򷵻�0��                            */
/**************************************************/

int notEqual(int row,int j,int (*chess)[8])
{ 
   int i,k,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
   for(i=0;i<8;i++)
      if(*(*(chess+i)+j)!=0)
      {
        flag1=1;
        break;
      } /*�ж��з���*/
	 
    for(i=row,k=j;i>=0 && k>=0;i--,k--)
         if(*(*(chess+i)+k)!=0)
         {
	flag2=1;
	break;
         }/*�ж����Ϸ�*/

   for(i=row,k=j;i<8 && k<8;i++,k++)
        if(*(*(chess+i)+k)!=0)
        {
	flag3=1;
	break;
       }/*�ж����·���*/

   for(i=row,k=j;i>=0 && k<8;i--,k++)
       if(*(*(chess+i)+k)!=0)
       {
	flag4=1;
	break;
       }/*�ж����Ϸ���*/
  for(i=row,k=j;i<8 && k>=0;i++,k--)
     if(*(*(chess+i)+k)!=0)
     {
	flag5=1;
	break;
    }/*�ж����·���*/

   if(flag1==1||flag2==1||flag3==1
	   ||flag4==1||flag5==1)return 0;  /*�����һ�����򲻷���Ҫ���򷵻�0��*/
				/*������row�е�j�в��ܰڷŻʺ�*/
   else return 1;    /*���򷵻�1*/
}


/***************************************************/
/*EightQueen����ʵ�ְ˻ʺ�����ĵݹ�   */
/*��⡣���γɷ���Ҫ��İ˻ʺ����̾���  */
/*ʱ����ӡ�����̵Ĳ��֣���һ��0-1����  */
/*��ʾ���̣�0����գ�1����ʺ�      */
/*������row��ʾ��ʼ�У�n��ʾ��������8 */
/*(*chess)[8]Ϊָ������ÿһ�е�ָ��      */
/**************************************************/

EightQueen(int row,int n,int (*chess)[8])
{
    int j;
    int k,t;
    int chess2[8][8];
    for(int i=0;i<8;i++)
         for(j=0;j<8;j++)
             chess2[i][j]=*(*(chess+i)+j);		/*�������̣������ݹ�ʹ��*/
    if(row==8)							/*�ݹ�����������γɷ���Ҫ��İ˻ʺ����̾���*/
       {
          for(k=0;k<8;k++){
            for(t=0;t<8;t++)
                printf("%d ",*(*(chess2+k)+t));      /*��ӡ����*/
            printf("\n");
          }
		  printf("\n\n");
		  getchar();
		  count++;                	 /*��¼��ĸ���*/
       }
   else{                            	/*�����ϵݹ�����������������еݹ�����*/

    for(j=0;j<n;j++) {                    
        if(notEqual(row,j,chess))       /*�ж����̵ĵ�row�е�j���ܷ�ڷ�һ���ʺ�*/
        {
            for(i=0;i<8;i++)
	*(*(chess2+row)+i)=0;
            *(*(chess2+row)+j)=1;     		/*�����̵ĵ�row�е�j�аڷŻʺ�*/
          EightQueen (row+1,n,chess2);   	/*�ݹ�ص���EightQueen����*/  
       }/*endif*/	
      }/*endfor*/
    }/*end else*/        
}

/*������*/
main()
{
   int chess[8][8],i,j;
   for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            chess[i][j]=0;                       /*��ʼ�����̣�ȫ����0*/

   EightQueen(0,8,chess);    /*���� EightQueen������������n=0��row=8��*/
/*chessΪָ������ÿһ�е�ָ��  */             
   printf("The number of the answer for eightqueen is\n");     /*����˻ʺ�����Ľ�ĸ���*/
   printf("%d\n\n",count);
}
