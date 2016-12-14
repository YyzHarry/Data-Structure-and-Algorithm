#include <iostream>
#include <memory.h>
#include <stdio.h>
using namespace std;

int pre[50001] = {};
int vis[50001] = {};

int find(int x)
{
    int r = x;
    while(pre[r] != r)
        r = pre[r];
    int i=x, j;
    while(pre[i] != r){
        j = pre[i];
        pre[i] = r;
        i=j;
    }
    return r;
}

void init(int *x,int a)
{
    for(int i=1;i<=a;i++)
        x[i] = i;
}

void join(int a, int b)
{
    int fa=find(a), fb=find(b);
    if(fa != fb) pre[fa] = fb;
}

int main()
{
    int n, m, cases=1;
    while(cin>>n>>m){
        if(n==0) break;
        int a,b,ans=0;
        memset(vis,0,sizeof(vis));
        init(pre, n);
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            join(a,b);
        }
        //for(int i=1;i<=n;i++) cout<<pre[i]<<endl;
        for(int i=1;i<=n;i++)
            if(!vis[find(i)]){
                vis[find(i)] = 1; ans++;
            }
        cout<<"Case "<<cases++<<": "<<ans<<endl;
    }
    return 0;
}
