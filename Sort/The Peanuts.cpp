#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int src[51][51];

struct Node
{
    int num;
    int x, y;
}p[2501];

bool cmp(Node a,Node b)
{
    return a.num > b.num;
}

int main()
{
    int t, m, n, k;
    cin>>t;
    while(t--){
        int cntnum=1, road=0, sum=0;
        cin>>m>>n>>k;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                cin>>src[i][j];
                if(src[i][j]){
                    p[cntnum].num = src[i][j];
                    p[cntnum].x = i;
                    p[cntnum++].y = j;
                }
            }
        sort(p+1,p+cntnum,cmp);

        //for(int i=1;i<cntnum;i++) cout<<p[i].num<<endl;

        p[0].x = 0, p[0].y = p[1].y;
        road += 2;
        for(int i=1;i<cntnum;i++){
            if(road + abs(p[i].x-p[i-1].x) + abs(p[i].y-p[i-1].y) + p[i].x + 1 <= k){
                sum += p[i].num;
                road += abs(p[i].x-p[i-1].x) + abs(p[i].y-p[i-1].y) + 1;

                //cout<<road<<endl;
            }
            else break;
        }
        cout<<sum<<endl;
    }
    return 0;
}
