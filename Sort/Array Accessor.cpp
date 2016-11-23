//A project using Quick Sort to implement array accessors


#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int a[100001];
int n,k,cnt=0;

bool exist(int now,int num)
{
    for(int p=now+1;p<n;p++){
        if(a[p] == num ){
            return 1;
        }
        if(a[p] > num) return 0;
    }
    return 0;
}

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    if(k < 0) k = -k;
    for(int j=0;j<n;j++){
        if(exist(j,a[j]+k))
            cnt++;
        while(a[j] == a[j+1]) j++;
    }
    cout<<cnt<<endl;
    return 0;
}
