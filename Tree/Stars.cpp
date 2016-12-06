#include<iostream>
#include<memory.h>
using namespace std;

const int MAX = 32010;
int lev[MAX], c[MAX];

int lowbit(int x)
{
    return x & (-x);
}

void add(int i,int data)
{
    while(i < MAX){
        c[i] += data;
        i += lowbit(i);
    }
}

int getsum(int x)
{
    int sum=0;
    while(x > 0){
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

int main()
{
    int x, y, n;
    cin>>n;
    memset(c,0,sizeof(c));
    memset(lev,0,sizeof(lev));
    for(int i=0;i<n;i++){
        cin>>x>>y;
        x++;
        lev[getsum(x)]++;
        add(x,1);
    }
    for(int i=0;i<n;i++)
        cout<<lev[i]<<endl;
    return 0;
}
