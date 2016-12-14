#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int pre[751];

struct edge
{
    int from, to;
    double wei;
}e[281250];
bool cmp(edge a,edge b)
{
    return a.wei < b.wei;
}

struct point
{
    double x, y;
}p[751];

int find(int x)
{
    if(x != pre[x])
        pre[x] = find(pre[x]);
    return pre[x];
}
void init(int *x,int n)
{
    for(int i=0;i<=n;i++)
        x[i] = i;
}

int main()
{
    int n, m, a, b, esum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    cin>>m;
    init(pre,n);
    while(m--){
        scanf("%d%d",&a,&b);
        ///注意已有边应find处理，不能直接pre
        int fa=find(a), fb=find(b);
        pre[fa] = fb;
    }
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
            e[esum].from = i;
            e[esum].to = j;
            e[esum].wei = sqrt(pow(p[i].x-p[j].x,2)+pow(p[i].y-p[j].y,2));
            esum++;
        }

    sort(e,e+esum,cmp);
    for(int i=0;i<esum;i++){
        int fa=find(e[i].from), fb=find(e[i].to);
        if(fa != fb){
            pre[fa] = fb;
            printf("%d %d\n",e[i].from,e[i].to);
        }
    }
    return 0;
}
