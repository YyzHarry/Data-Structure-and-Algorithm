#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

map<char,int> m;
int n, flag=0, a[10000000]={0};
string str;

int trans(string s)
{
    int l = s.length(), tmp=0;
    for(int i=0;i<l;i++)
        if(isalnum(s[i])){
            if(s[i]>='0' && s[i]<='9'){
                tmp *= 10;
                tmp += s[i] -'0';
            }
            else{
                tmp *= 10;
                tmp += m[s[i]];
            }
        }
    return tmp;
}

void print(int x)
{
    for(int i=1000000;i>=1;i/=10){
        cout<<x/i;
        x %= i;
        if(i == 10000) cout<<"-";
    }
}

int main()
{
    m['A']=m['B']=m['C']=2, m['D']=m['E']=m['F']=3, m['G']=m['H']=m['I']=4,
    m['J']=m['K']=m['L']=5, m['M']=m['N']=m['O']=6, m['P']=m['R']=m['S']=7,
    m['T']=m['U']=m['V']=8, m['W']=m['X']=m['Y']=9;
    cin>>n;
    while(n--){
        cin>>str;
        a[trans(str)]++;
    }
    for(int i=0;i<10000000;i++){
        if(a[i] > 1){
            flag=1;
            print(i);
            cout<<" "<<a[i]<<endl;
        }
    }
    if(!flag) cout<<"No duplicates."<<endl;
    return 0;
}
