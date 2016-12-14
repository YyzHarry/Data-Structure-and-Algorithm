#include<iostream>
using namespace std;

int pre[1001];
int vis[1001] = {0};
int dis[1001];///用于记录前一个敌人

int find(int x)
{
    if(x != pre[x])
        pre[x] = find(pre[x]);
    return pre[x];
}
void join(int a,int b)
{
    int fa=find(a), fb=find(b);
    if(fa != fb)
        pre[fa] = fb;
}
void init(int *x,int n)
{
    for(int i=1;i<=n;i++)
        x[i] = i;
}

int main()
{
    int n, m, a, b, ans=0;
    char s;
    cin>>n>>m;
    init(pre,n);
    while(m--){
        cin>>s>>a>>b;
        if(s == 'F') join(a,b);
        else{
            if(dis[a]) join(dis[a],b);
            if(dis[b]) join(a,dis[b]);
            dis[a] = b;///上一个敌人
            dis[b] = a;
        }
    }
    for(int i=1;i<=n;i++)
        if(!vis[find(i)]){
            vis[find(i)] = 1;
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
