#include<iostream>
using namespace std;

struct node{
    int farnum;
    int sonnum;
    int son[110];
}v[1000];

int vis[1000]={0};

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int p,q;
        cin>>p>>q;
        v[p].son[v[p].sonnum++] = q;
        v[q].farnum++;
    }
    int cnum=0;
    while(cnum<n){
        for(int i=1;i<=n;i++)
            if(!vis[i] && v[i].farnum==0){
                vis[i] = 1;
                cout<<"v"<<i<<" ";
                for(int ii=0;ii<v[i].sonnum;ii++)
                    v[v[i].son[ii]].farnum--;
                break;
            }
        cnum++;
    }
    return 0;
}
