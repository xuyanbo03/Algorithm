#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class CAnalysisTable
{
public:
    int mAnalysisTable;
    int nAnalysisTable;
    vector<vector<char *> > AnalysisTable;

    CAnalysisTable(int m, int n);
    CAnalysisTable(int m,int n,char *string[]);

    bool LL1(char* inputstring);
    int GetRow(char a);
    int GetColumn(char a);
    void Show();
    bool IsVt(char c);
};

int main()
{
    char *string[]={"","i","+","*","(",")","#",
                    "E","TA","","","TA","","",
                    "A","","+TA","","","$","$",
                    "T","FB","","","FB","","",
                    "B","","$","*FB","","$","$",
                    "F","i","","","(E)","",""};
    CAnalysisTable table(6,7,string);
    table.Show();
    //char a='ε';
    char a='$';

    char symbolstring[80];
    char ch;
    do{
        printf("输入符号串:\n");
        scanf("%s",symbolstring);
        bool flag=table.LL1(symbolstring);
        if(flag == false)
            cout<<endl<<"不接受字符串:"<<symbolstring<<endl<<endl;
        else
            cout<<endl<<"接受字符串："<<symbolstring<<endl<<endl;
        cout<<"继续输入y，退出输入n "<<endl;
        ch=getchar();
        while (ch!='y' && ch!='n')
            ch=getchar();
    }while(ch == 'y');

    return 0;
}

CAnalysisTable::CAnalysisTable(int m, int n, char *string[])
{
    int i,j;
    mAnalysisTable=m;
    nAnalysisTable=n;
    vector<char *> Table;
    for(i=0;i<m;i++)
    {
        Table.clear();
        for(j=0;j<n;j++)
        {
            Table.push_back(string[i*n+j]);
        }
        AnalysisTable.push_back(Table);
    }
}

CAnalysisTable::CAnalysisTable(int m, int n)
{
    int i,j;
    mAnalysisTable=m;
    nAnalysisTable=n;
    vector<char *> Table;
    for(i=0;i<m;i++)
    {
        Table.clear();
        for(j=0;j<n;j++)
        {
            Table.push_back("");
        }
        AnalysisTable.push_back(Table);
    }
}

void CAnalysisTable::Show()
{
    int i,j;
    cout.setf(ios::left,ios::adjustfield);
    for(i=0;i<mAnalysisTable;i++)
    {
        for(j=0;j<nAnalysisTable;j++)
            cout<<setw(7)<<AnalysisTable[i][j];
        cout<<endl;
    }
    cout<<endl<<endl;
}

int CAnalysisTable::GetColumn(char a)
{
    int n=-1;
    char aa[2];
    aa[0]=a;
    aa[1]=0;
    for(int i=0;i<nAnalysisTable;i++)
        if(strcmp(aa,AnalysisTable[0][i])==0)
            n=i;
    return n;

}

int CAnalysisTable::GetRow(char a)
{
    char aa[2];
    aa[0]=a;
    aa[1]=0;

    for(int i=0;i<mAnalysisTable;i++)
        if(strcmp(aa,AnalysisTable[i][0])==0)
            return i;
    return -1;
}

bool CAnalysisTable::LL1(char* inputstring)
{
    //if(inputstring.Right(1)!="#")return false;
    int i=0;
    char a;
    char x;
    bool flag=true;
    vector<char> stack;
    stack.push_back('#');
    stack.push_back(this->AnalysisTable[1][0][0]);
    a=inputstring[i];
    int step=0;
    int n=strlen(inputstring);
    int width=16;
    char *p="";
    char oldx;
    cout.setf(ios::left,ios::adjustfield);
    cout<<setw(width)<<"step"<<setw(width)<<"stack"<<setw(width)<<"string"<<setw(width)<<"production"<<endl<<endl;
    while(flag)
    {
        x=stack[stack.size()-1];
        //输出分析步骤
        char stacks[80];
        int j;
        for(j=0;j<stack.size();j++)
            stacks[j]=stack[j];
        stacks[j]=0;
        if(strcmp(p,"")!=0)
            cout<<setw(width)<<step<<setw(width)<<stacks<<setw(width)<<inputstring+i<<oldx<<"-->"<<p<<endl;
        else
            cout<<setw(width)<<step<<setw(width)<<stacks<<setw(width)<<inputstring+i<<setw(width)<<endl;
        step++;
        p="";
        oldx=x;
        //x=a="#",分析成功，停止分析过程
        if(x==a&&a=='#')
        {
            flag=true;
            break;
        }
        else
        {
            if(x==a&&a!='#')
            {
                //x=a!="#",x出栈，读入下一个a
                stack.pop_back();
                i++;
                a=inputstring[i];
            }
            else
            {
                //x是个非终止符，察看分析表M
                int ai=this->GetRow(x);
                int aj=this->GetColumn(a);
                if(ai==-1||aj==-1)
                {
                    //如果找不到产生式，出错
                    flag=false;
                    break;
                }
                p=this->AnalysisTable[ai][aj];
                if(strcmp(p,"")==0)
                {
                    //如果找不到产生式，出错
                    flag=false;
                    break;
                }

                if(strcmp(p,"$")==0)
                {
                    //如果产生式右部是空串，则没有东西进栈
                    stack.pop_back();
                }
                else
                {
                    //x出栈，产生式右部进栈
                    stack.pop_back();
                    int n=strlen(p);
                    for(int i=n-1;i>=0;i--)
                        stack.push_back(p[i]);
                }
            }
        }
    }
    return flag;
}

bool CAnalysisTable::IsVt(char c)
{
    bool b=false;
    char aa[2];
    aa[0]=c;
    aa[1]=0;
    for(int i=0;i<nAnalysisTable;i++)
        if(strcmp(aa,AnalysisTable[0][i])==0)
            b=true;
    return b;
}