#include "stdio.h"

void loopMove(char *str, int n)
{
    int i,j,strLength;
    char tmp;
    strLength = strlen(str);
    for(i=0;i<n;i++)
    {
        tmp = str[strLength-1];					/*ȡ���ַ��������һ��Ԫ��*/
        for(j=0;j<strLength-1;j++)
        {
            str[strLength-j-1] = str[strLength-j-2];	/*ǰ���Ԫ�غ���*/
        }
        str[0] = tmp;							/*��ԭ�ַ���β����Ԫ�ط����ַ����ײ�*/
    }
}

main()
{
    char *str="abcdefghijklmn";					/*��ʼ���ַ���str*/
    printf("The orginal string is %s\n",str);			/*��ӡ�����ַ���*/
    loopMove(str,6);							/*ѭ������6λ*/
    printf("The string be loopmoved is %s\n",str);	/*��ӡ��ѭ�����ƺ���ַ���str*/
    getche();
}
