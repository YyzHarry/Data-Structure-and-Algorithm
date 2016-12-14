///此题与 发现他抓住他 类似 属于并查集应用
///需要自己推导出递推关系
///详细http://www.cnblogs.com/dongsheng/archive/2013/06/12/3133188.html
///--------------------------------------------------------------------

#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;

int pre[50005];
int vis[50005]={0};
int n, k, ans=0;

//更新的步调，先将当前点节与其根点节相连，然后更新其与根点节的关系
//当前节点x与根节点r的关系更新的方法：
///    (x与其父点节的关系+其父点节的关系与根点节的关系)%3
//所以在更新节点x的数据之前需要更新其父节点的数据，这是find为什么搞成递归函数的原因
//其更新的次序是从根节点开始往下，始终到当前点节x的父点节。
int find(int x)
{
    if(x != pre[x]){
        int r = pre[x];
        pre[x] = find(pre[x]);
        //更新当前点节与根点节的关系，由x->x父和x父->父根的关系失掉x->父根的关系
        //所以在这之前必须更新其父点节与根点节的关系
        vis[x] = (vis[x]+vis[r])%3;
    }
    return pre[x];
}

void init(int *x,int a)
{
    for(int i=0;i<a;i++)
        x[i] = i;
}

int main()
{
    cin>>n>>k;
    init(pre, n);
    for(int i=0, d,a,b;i<k;i++){
        scanf("%d%d%d",&d,&a,&b);
        if(a>n || b>n){ans++; continue;}
        if(d==2 && a==b){ans++; continue;}
        int fa=find(a), fb=find(b);
        if(fa == fb){
            if(d==1 && vis[a]!=vis[b]) ans++;
            //如果不是同类，加入x与y的关系之后，x相对根点节的关系(x根->y,y->x(即3-(d-1)=2).即x根->x)应该是不变的
            //这里d=2表示x - y = 2-1=1;而y->x=3-(x->y)=3-1=2;
            if(d==2 && vis[a]!=(vis[b] + 3-1)%3) ans++;
        }
        else{
            pre[fb] = fa;
            //(d-1)为x与y的关系，3-relation[y]是y与y的根点节的关系，注意方向，relation[x]是其根点节与x的关系
            //x根->x,x->y,y->y根：即x根->y根
            vis[fb] = (vis[a] + d-1 + 3-vis[b])%3;///注意这里只更新的是fy相对于根的关系
        }

    }
    cout<<ans<<endl;
    return 0;
}
