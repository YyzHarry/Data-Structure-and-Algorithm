#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 500001;
int t[MAX], a[MAX];
long long ans;

void merge(int *a,int left,int mid,int right)
{
    int l=left, r=mid+1, now=0;
    while(l<=mid && r<=right){
        if(a[l] > a[r]){
            t[now++] = a[r++];
            ans += mid-l+1;
        }
        else t[now++] = a[l++];
    }
    while(l<=mid) t[now++] = a[l++];
    while(r<=right) t[now++] = a[r++];
    for(int i=0;i<now;i++)
        a[left+i] = t[i];
}

void merge_sort(int *a,int left,int right)
{
    if(left < right){
        int mid = (left + right)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}

int main()
{
    int n;
    while(cin>>n && n){
        ans = 0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        merge_sort(a,1,n);
        cout<<ans<<endl;
    }
    return 0;
}
