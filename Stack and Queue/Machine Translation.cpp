#include<iostream>
#include<queue>
#include<set>
using namespace std;

int main()
{
    set<int> s;
    queue<int> q;
    int n, m, a, ans=0;
    cin>>m>>n;
    while(n--){
        cin>>a;
        if(!s.count(a)){
            if(s.size() == m){
                s.erase(q.front());
                q.pop();
            }
            q.push(a);
            s.insert(a);
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
