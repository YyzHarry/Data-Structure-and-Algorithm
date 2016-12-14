#include<iostream>
#include<algorithm>
using namespace std;

int pre[101];
int src[101][101];

struct edge
{
    int from, to, wei;
}e[5050];
bool cmp(edge a,edge b)
{
    return a.wei < b.wei;
}

int find(int x)
{
    if(x != pre[x])
        pre[x] = find(pre[x]);
    return pre[x];
}
void init(int *x,int a)
{
    for(int i=0;i<a;i++)
        x[i] = i;
}

int main()
{
    int n;
    while(cin>>n){
        int ans=0, esum=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            cin>>src[i][j];

        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++){
                e[esum].from = i;
                e[esum].to = j;
                e[esum].wei = src[i][j];
                esum++;
            }
        //kruskal
        init(pre,n);
        sort(e,e+esum,cmp);
        for(int i=0;i<esum;i++){
            int fa=find(e[i].from), fb=find(e[i].to);
            if(fa != fb){
                ans += e[i].wei;
                pre[fa] = fb;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
