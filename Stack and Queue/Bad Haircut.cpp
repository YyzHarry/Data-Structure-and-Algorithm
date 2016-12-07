#include<iostream>
using namespace std;
int q[80001], rear=-1, input, n;
long long ans=0;
int main()
{
    cin>>n;
    while(n--){
        cin>>input;
        while(rear>=0 && input>=q[rear]) rear--;
        q[++rear] = input;
        ans += rear;
    }
    cout<<ans<<endl;
    return 0;
}
