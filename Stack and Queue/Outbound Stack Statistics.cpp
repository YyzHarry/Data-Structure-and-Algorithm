#include<iostream>
using namespace std;

///���ƽⷨ
int main()
{
    int a[16][16]={0};
    int n; cin>>n;
    for(int i=1;i<=n;i++) a[i][0]=1;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(j<i) a[i][j]=a[i-1][j]+a[i][j-1];
        if(i==j) a[i][j]=a[i][j-1];
    }
    cout<<a[n][n]<<endl;
    return 0;
}

///�������ѽⷨ
int n,ans=0;
void dfs(int top,int head) ///topջ����head�ж���Ԫ�����ջ
{
    if(head == n) {ans++; return;}
    if(top > 0) dfs(top-1,head);
    if(head < n) dfs(top+1,head+1);
    return ;
}
int main()
{
    cin>>n;
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}
