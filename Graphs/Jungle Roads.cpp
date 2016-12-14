#include<iostream>
#include<algorithm>
using namespace std;

int ans, edgsum; //总边数
int pre[76];
//edge结构
struct edge
{
    int from, to, wei;
}e[76];
bool cmp(edge a,edge b)
{
    return a.wei<b.wei;
}
//并查集合并
int find(int x)
{
    int r = x;
    while(r != pre[r])
        r = pre[r];
    int i=x, j;
    while(i != pre[r]){
        j = pre[i];
        pre[i] = pre[r];
        i = j;
    }
    return pre[r];
}

void init(int *x,int a)
{
    for(int i=0;i<=a;i++)
        x[i] = i;
}

int main()
{
    int n;
    while(cin>>n && n){
        edgsum=0; //在这里初始化！
        for(int i=1;i<n;i++){
            char t, y;
            int k, q;
            cin>>t>>k;
            while(k--){
                cin>>y>>q;
                e[edgsum].from = t-'A';
                e[edgsum].to = y-'A';
                e[edgsum].wei = q;
                edgsum++;
            }
        }

        //Kruskal
        ans = 0;
        init(pre, n);
        sort(e,e+edgsum,cmp);
        for(int i=0;i<edgsum;i++){
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
