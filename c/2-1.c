#include "stdio.h"
typedef struct student{
    int id;                /*ѧ�����*/
    char name[10];        /*ѧ������*/
    float score;            /*�ɼ�*/ 
}Student;

int search(Student stu[],int n,int key){
    int i;
    for(i=0; i<n; i++)
        if( stu[i].id == key )            /*���ҳɹ�*/
            return i;               
    return -1;                         /*����ʧ��*/
 
}
main()
{
    Student stu[4] = {{1004,"TOM",100} ,    
                      {1002,"LILY",95},
                      {1001,"ANN",93},
                      {1003,"LUCY",98}
                      };                        /*��ʼ���ṹ������*/
    int addr;                                /*Ҫ���ҵļ�¼�ĵ�ַ*/
    addr = search(stu,4,1001);
    printf("Student ID:   %d\n",stu[addr].id);         /*������ҵ��ļ�¼����Ϣ*/
    printf("Student name: %s\n",stu[addr].name);
    printf("Student score: %f\n",stu[addr].score);
    getche();
}

