#include<iostream>
#include<memory.h>
using namespace std;

int src[1001][1001];
bool vis[1001];
int weigh[1001];

int main()
{
    int k;  cin>>k;
    for(int i=1;i<=k;i++){
        int n, m;
        cin>>n>>m;
        memset(src,0,sizeof(src));
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=m;j++){
            int a, b, tmp;
            cin>>a>>b>>tmp;
            if(src[a][b] < tmp) src[a][b] = tmp;
            src[b][a] = src[a][b];
        }
        for(int i=1;i<=n;i++)
            weigh[i] = src[1][i];
        //dijkstra
        for(int i=1;i<=n;i++){
            int v, maxx=-1;
            for(int j=1;j<=n;j++)
                if(!vis[j] && weigh[j]>maxx){
                    maxx = weigh[j];
                    v = j;
                }
            vis[v] = true;
            for(int j=1;j<=n;j++)
                if(!vis[j] && weigh[j]<min(weigh[v],src[j][v]))
                    weigh[j] = min(weigh[v],src[j][v]);
        }
        cout<<"Scenario #"<<i<<":"<<endl;
        cout<<weigh[n]<<endl<<endl;
    }
    return 0;
}
