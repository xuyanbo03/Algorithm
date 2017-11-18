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
    for(int i = 0; i < node[x].size(); i++)  //与x有关系的皇家飞行员  
    {  
        int y = node[x][i];  
        if(vis[y]==false)    
        {  
            vis[y]=true; //如果y没有和别人配对，或已经与y配对的人可以找到其他的伴侣，就可以与y配对。  
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
    while(~scanf("%d%d",&m,&n))   //m是外籍飞行员的数量，n是皇家飞行员的数目。  
    {  
        int foreign,home;    //外籍飞行员编号，国内飞行员编号  
        memset(node,0,sizeof(node));  
        while(1)  
        {  
            scanf("%d%d",&foreign,&home);  
            if(foreign == -1 && home== -1)
				break;
            node[foreign].push_back(home);  
            node[home].push_back(foreign);  
        }
        
		int ans = 0; //对m个外籍飞行员进行匹配  
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

