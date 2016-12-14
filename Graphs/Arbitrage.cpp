#include<iostream>
#include<memory.h>
#include<map>
using namespace std;

map<string,int> v1;
double src[31][31];

int main()
{
    int n, m, cases=1;
    double t;
    string s1, s2;
    while(cin>>n && n){
        int flag=0;
        for(int i=0;i<n;i++){
            cin>>s1;
            v1[s1] = i;
        }
        cin>>m;
        memset(src,0,sizeof(src));
        for(int i=0;i<n;i++) src[i][i] = 1;

        for(int i=0;i<m;i++){
            cin>>s1>>t>>s2;
            src[v1[s1]][v1[s2]] = t;
        }

        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(src[i][j] < src[i][k]*src[k][j])
                        src[i][j] = src[i][k]*src[k][j];

        for(int i=0;i<n;i++)
            if(src[i][i]>1){
                flag = 1; break;
            }
        cout<<"Case "<<cases++<<": ";
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
