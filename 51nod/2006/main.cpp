#include <iostream>  
#include <stdio.h>  
#include <vector>  
#include <string.h>  
  
using namespace std;  
  
const int maxn = 1000;  
vector<int> node[maxn];  
bool vis[maxn];  
int match[maxn];

bool dfs(int x)  
{  
    for(int i = 0; i < node[x].size(); i++)  //��x�й�ϵ�Ļʼҷ���Ա  
    {  
        int y = node[x][i];  
        if(vis[y]==false)    
        {  
            vis[y]=true; //���yû�кͱ�����ԣ����Ѿ���y��Ե��˿����ҵ������İ��£��Ϳ�����y��ԡ�  
            if(match[y]==-1 || dfs(match[y]))  
            {  
                match[y] = x;  
                match[x] = y;  
                return true;  
            }  
        }  
    }  
    return false;  
}

int main()
{  
    int m,n;  
    while(~scanf("%d%d",&m,&n))   //m���⼮����Ա��������n�ǻʼҷ���Ա����Ŀ��  
    {  
        int foreign,home;    //�⼮����Ա��ţ����ڷ���Ա���  
        memset(node,0,sizeof(node));  
        while(1)  
        {  
            scanf("%d%d",&foreign,&home);  
            if(foreign == -1 && home== -1)
				break;
            node[foreign].push_back(home);  
            node[home].push_back(foreign);  
        }
        
		int ans = 0; //��m���⼮����Ա����ƥ��  
        memset(match,-1,sizeof(match));  
        for(int i = 1; i <= m; i++)  
        {  
            memset(vis,false,sizeof(vis));  
            if(dfs(i))  
                ans++;  
        }  
        if(ans == 0)  
            printf("No Solution\n");  
        else  
            printf("%d\n",ans);  
    }  
    return 0;  
}  

