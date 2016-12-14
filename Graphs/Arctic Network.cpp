#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
using namespace std;

int pre[505];
int x[505], y[505];
double vis[124800];

struct edge
{
    int from, to;
    double wei;
}e[124800];
bool cmp(edge a,edge b)
{
    return a.wei < b.wei;
}

int find(int x)
{
    if(x != pre[x])
        return find(pre[x]);
    return pre[x];
}
void init(int *x,int n)
{
    for(int i=0;i<n;i++)
        x[i] = i;
}

int main()
{
    int t; cin>>t;
    while(t--){
        int s, p;
        cin>>s>>p;
        for(int i=0;i<p;i++)
            cin>>x[i]>>y[i];
        int k=0, esum=0;
        for(int i=0;i<p;i++)
            for(int j=i+1;j<p;j++){
                e[esum].from = i;
                e[esum].to = j;
                e[esum].wei = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                esum++;
            }
        //kruskal
        init(pre,p);
        sort(e,e+esum,cmp);
        for(int i=0;i<esum;i++){
            int fa=find(e[i].from), fb=find(e[i].to);
            if(fa != fb){
                vis[k++] = e[i].wei;
                pre[fa] = fb;
            }
        }
        sort(vis,vis+k);
        printf("%.2f\n",vis[k-s]);
    }
    return 0;
}
