#include<iostream>
#include<map>
using namespace std;

const int INF = 65535;

map<string,int> v1;
map<int,string> v2;

int main()
{
    int p, q, r;
    string s1, s2;
    cin>>p;
    for(int i=1;i<=p;i++){
        cin>>s1;
        v1[s1] = i;
        v2[i] = s1;
    }
    int gra[p+1][p+1], src[p+1][p+1];

    ///src初始化 memset不能用
    for(int i=1;i<=p;i++)
        for(int j=1;j<=p;j++) src[i][j] = INF;

    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>s1>>s2;
        int tmp; cin>>tmp;
        ///注意此处地点之间的距离可能会出现多次，要取最短的存
        if(tmp < src[v1[s1]][v1[s2]])
            src[v1[s1]][v1[s2]] = tmp;
        src[v1[s2]][v1[s1]] = src[v1[s1]][v1[s2]];
    }
    for(int i=1;i<=p;i++)
        for(int j=1;j<=p;j++)
            gra[i][j] = src[i][j];

    int pre[p+1][p+1];
    for(int i=1;i<=p;i++)
        for(int j=1;j<=p;j++)
            pre[i][j] = j;

    ///floyd,pre数组记录前驱节点
    for(int k=1;k<=p;k++)
        for(int i=1;i<=p;i++)
            for(int j=1;j<=p;j++)
                if(src[i][j] > (src[i][k]+src[k][j])){
                    src[i][j] = src[i][k]+src[k][j];
                    pre[i][j] = pre[i][k];
                }

    cin>>r;
    while(r--){
        cin>>s1>>s2;
        if(s1 == s2) cout<<s2<<endl;
        else{
            int k = pre[v1[s1]][v1[s2]];
            cout<<s1<<"->("<<gra[v1[s1]][k]<<")->";
            while(k != v1[s2]){
                cout<<v2[k]<<"->("<<gra[k][pre[k][v1[s2]]]<<")->";
                k = pre[k][v1[s2]];
            }
            cout<<s2<<endl;
        }
    }

    return 0;
}
