#include<iostream>
#include<memory.h>
using namespace std;
char src[9][9];
int ans, n, k;
bool vis[9];
void dfs(int row,int col,int deep)
{
    if(deep == k-1){
        ans++; return;
    }
    vis[col] = true;
    for(int i=row+1;i<n;i++)
        for(int j=0;j<n;j++)
            if(!vis[j] && src[i][j]=='#'){
                vis[j] = true;
                dfs(i,j,deep+1);
                vis[j] = false;
            }
    return ;
}
int main()
{
    while(cin>>n>>k){
        if(n==-1 || k==-1) break;
        ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>src[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(src[i][j] == '#'){
                    vis[j] = true;
                    dfs(i,j,0);
                    vis[j] = false;
                }
        cout<<ans<<endl;
    }
    return 0;
}
