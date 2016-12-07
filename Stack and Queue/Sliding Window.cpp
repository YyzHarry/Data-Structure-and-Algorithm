#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;

const int MAX = 1000001;
int a[MAX];
int ans1[MAX], ans2[MAX];

struct cmp1
{
    bool operator()(int x,int y){
        return a[x] > a[y];
    }
};
struct cmp2
{
    bool operator()(int x,int y){
        return a[x] < a[y];
    }
};
priority_queue<int,vector<int>,cmp1> q1;
priority_queue<int,vector<int>,cmp2> q2;

int main()
{
    int n, k, now=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<k;i++){
        q1.push(i);
        q2.push(i);
    }
    ans1[now] = a[q1.top()];
    ans2[now++] = a[q2.top()];

    for(int i=k;i<n;i++){
        q1.push(i);
        q2.push(i);
        while(i-q1.top() >= k) q1.pop();
        ans1[now] = a[q1.top()];
        while(i-q2.top() >= k) q2.pop();
        ans2[now++] = a[q2.top()];
    }
    for(int i=0;i<now;i++)
        cout<<ans1[i]<<" ";
    cout<<endl;
    for(int i=0;i<now;i++)
        cout<<ans2[i]<<" ";
    return 0;
}
