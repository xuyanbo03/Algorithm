#include "stdio.h"

int bitNumber(unsigned char c)
{
    int count = 0;
    int i;
    unsigned char cmp = (0x1<<7);
    for(i=0;i<8;i++)
    {
        if((c & cmp)!=0)			/*��������Ϊ0*/
            count++;			/*����count��¼�ַ��С�1���ĸ���*/
        cmp = cmp>>1;			/*������'1'λ�����ƶ�1λ*/
    }
    return count;
}

main()
{
    unsigned char c;
    printf("Please input a character\n");		/*����1���ַ�*/
    scanf("%c",&c);
    printf("The number of bit '1' in the character are %d\n",bitNumber(c)); /*������ַ��С�1��λ�ĸ���*/
    getche();
}
