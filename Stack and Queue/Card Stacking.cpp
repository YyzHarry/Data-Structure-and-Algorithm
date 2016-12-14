#include<iostream>
#include<algorithm>
using namespace std;

int n, k, p, loop=1, j=0;
int a[100001]={0},b[50001];

int find(int now)
{
    while(a[now] && now<k) now++;
    if(now<k) return now;
    else{
        now=0;
        return find(now);
    }
}

int main()
{
    cin>>n>>k>>p;
    int m = k/n, now=0, sum=k;
    for(int i=0;i<k;i++){
        if((i+1)%n == 0)
            b[j++] = now;
        a[now] = 1;
        if(i == k-1) break;
        now = find(now);

        for(int c=0;c<p;c++){
            now++;
            now = find(now);
        }
    }
    sort(b,b+j);
    for(int i=0;i<j;i++) cout<<b[i]+1<<endl;
    return 0;
}
