                 int IsNarcissus(int a);
void Narcissus();
void main()
{
    printf("The Narcissus numbers below are\n");
    Narcissus();
    getche();
}

void Narcissus()
{   /*Ѱ��100-999֮���ˮ�ɻ���*/
    int i;
    for(i=100;i<=999;i++)
        if(IsNarcissus(i))
            printf("%d ",i);
}

int IsNarcissus(int a)
{     /*�ж��Ƿ���ˮ�ɻ��������򷵻�1�����Ƿ���0*/
    int sum=0,tmp;
    tmp=a;
    while(tmp>0)
    {
        sum=sum+(tmp%10)* (tmp%10)*(tmp%10);
        tmp=tmp/10;

    }
    if(sum==a)
        return 1;         /*a ��ˮ�ɻ���*/
    else
        return 0;         /* a ����ˮ�ɻ���*/
}

