// Initially I use Set to mark the array
// But it leads Time Limit Exceeded
// In fact we can only use an extra array to mark conditions
// Also, "q.size()" is needed

#include<iostream>
#include<queue>
#include<set>
using namespace std;

queue<int> q;
bool vis[1000001]={0};

int main()
{
    /*
    set<int> s;
        if(!s.count(a))
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
    */
    int n, m, a, ans=0;
    cin>>m>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(!vis[a]){
            if(q.size() == m){
                vis[q.front()] = 0;
                q.pop();
            }
            q.push(a);
            vis[a] = 1;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
