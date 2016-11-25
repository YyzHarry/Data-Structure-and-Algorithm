#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int pre[30001];

int find(int x)
{
    if(x != pre[x])
        pre[x] = find(pre[x]);
    return pre[x];
}

void init(int *a,int n)
{
    for(int i=0;i<n;i++)
        a[i] = i;
}

int main()
{
    int m, n, k, f, tmp;
    while(1){
        int ans=1;
        cin>>m>>n;
        if(m==0 && n==0) break;

        init(pre,m);

        for(int i=0;i<n;i++){
            cin>>k>>f;
            for(int j=0;j<k-1;j++){
                cin>>tmp;
                int fa=find(f), fb=find(tmp);
                if(fa != fb)
                    pre[fa] = fb;
            }
        }
        for(int i=1;i<m;i++)
            if(find(0) == find(i)) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
