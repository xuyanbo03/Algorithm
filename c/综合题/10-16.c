#include "stdio.h"

void mystrcpy(char *src,char *dst)
{
    int i=0;
    while(src[i] != '\0')
    {
       dst[i] = src[i];
       i++;
    }
    dst[i] = '\0';
}

main()
{
    char dst[14],*src="hello world!\n";		/*����Դ�ַ�����Ŀ���ַ���*/
    printf("src: %s",src);						/*��ӡ��Դ�ַ���src�е�����*/
    mystrcpy(src,dst);					/*���ú���mystrcpy �����ַ�������*/
    printf("dst: %s",dst);						/*��ӡ��Ŀ���ַ���dst�е�����*/
    getche();
}
