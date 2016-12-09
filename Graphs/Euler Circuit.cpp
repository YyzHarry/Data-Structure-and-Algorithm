#include<iostream>
#include<stack>
#include<string.h>
#include<stdio.h>
#include<map>
#include<memory.h>
#include<set>
#include<queue>
using namespace std;

int pre[1001];
int du[1001];

int find(int x)
{
    if(x != pre[x])
        pre[x] = find(pre[x]);
    return pre[x];
}

void init(int *a,int n)
{
    for(int i=0;i<=n;i++)
        a[i] = i;
}

int main()
{
    int n, m, a, b;
    while(cin>>n && n){
        cin>>m;
        init(pre,n); memset(du,0,sizeof(du));
        int flag=0;
        while(m--){
            cin>>a>>b;
            du[a]++; du[b]++;
            int fa=find(a), fb=find(b);
            if(fa != fb) pre[fa] = fb;
        }
        int root=0;
        for(int i=1;i<=n;i++)
            if(i == pre[i])
                root++;
        if(root != 1){
            cout<<"0"<<endl;
            continue;
        }
        flag=1;
        for(int i=1;i<=n;i++)
            if(du[i]%2 != 0) {flag=0; break;}
        if(flag) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
    return 0;
}
