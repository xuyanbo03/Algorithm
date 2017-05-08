#include <stdio.h>
#include <stdlib.h>

/*
递归反向输出字符串

字符串结束标志‘#’
输入字符串的一个字符，存到a中，递归调用Print（），直到遇到“#”
*/

Print()
{
    char a;
    scanf("%c",&a);
    if(a!='#')
        Print();
    if(a!='#')
        printf("%c",a);
}

main()
{
    printf("Please input a string ending for '#'\n");
    Print();
    getche();
}
