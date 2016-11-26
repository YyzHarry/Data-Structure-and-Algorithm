#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

char str[20000];
int res1=-1, res2=-1;

void dfs(int max1,int max2,int &i)
{
    res1 = max(res1,max1);
    res2 = max(res2,max2);
    int cnt=1;
    while(str[i]){
        if(str[i] == 'd'){
            dfs(max1+1,max2+cnt,++i);
            cnt++;
        }
        else{
            i++; return ;
        }
    }
}

int main()
{
    cin>>str;
    int i=0;
    dfs(0,0,i);
    cout<<res1<<" => "<<res2;
    return 0;
}
