// Memory:246328kB
// Time:4357ms
// Using Topological Sorting

#include<iostream>
#include<stdio.h>
#include<memory.h>
#include<queue>
using namespace std;

struct node_
{
    int num;
    int sonnum, farnum;
    int son[401];
}node[100001];

bool vis[100001];

int main()
{
    int n, m, t, a, b;
    cin>>t;
    while(t--){
        int flag=0;
        memset(vis,0,sizeof(vis));
        memset(node,0,sizeof(node));
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            node[b].farnum++;
            node[a].son[node[a].sonnum++] = b;
        }
        queue<node_> q;
        for(int i=1;i<=n;i++){
            node[i].num = i;
            if(node[i].farnum == 0)
                q.push(node[i]);
        }

        while(!q.empty()){
            node_ tmp = q.front();
            q.pop();
            vis[tmp.num] = 1;
            for(int i=0;i<tmp.sonnum;i++){
                node[tmp.son[i]].farnum--;
                if(node[tmp.son[i]].farnum == 0)
                    q.push(node[tmp.son[i]]);
            }
        }
        for(int i=1;i<=n;i++)
            if(!vis[i]) {flag=1; cout<<"Yes"<<endl; break;}
        if(!flag) cout<<"No"<<endl;
    }
    return 0;
}
