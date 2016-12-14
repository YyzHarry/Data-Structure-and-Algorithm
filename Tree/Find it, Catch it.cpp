#include<iostream>
#include<stdio.h>
#include<memory.h>
using namespace std;

int pre[100001];
int vis[100001];

int find(int x)
{
    if(x == pre[x]) return x;

    int r = pre[x];
    pre[x] = find(pre[x]);
    vis[x] = (vis[x]+vis[r])%2;

    return pre[x];
}

void init(int *x,int a)
{
    for(int i=1;i<=a;i++)
        x[i] = i;
}

void join(int a,int b)
{
    int fa=find(a), fb=find(b);
    if(fa != fb){
        pre[fb] = fa;
        vis[fb] = (vis[a] + 1 + 2-vis[b])%2;
        /// 根到fb == 根到a + a到b + b到fb
    }
}

int main()
{
    int n, m, t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        char str; int a, b;
        memset(vis,0,sizeof(vis));
        init(pre, n);
        while(m--){
            cin>>str>>a>>b;
            if(str == 'D')
                join(a, b);
            else{
                if(find(a) == find(b)){
                    if(vis[a] == vis[b]) cout<<"In the same gang."<<endl;
                    else cout<<"In different gangs."<<endl;
                }
                else cout<<"Not sure yet."<<endl;
            }
        }
    }
    return 0;
}
