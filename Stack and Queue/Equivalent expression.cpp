#include<map>
#include<stack>
#include<iostream>
using namespace std;
map<char,int> m;  ///���ַ�ӳ�䵽����
string s1,s2,r1,r2;
string transform(string s)///�ѱ��ʽת��Ϊ��׺���ʽ�������
{
    int i,j,len;
    char c[81];
    stack<char> exp;  ///����һ���ַ�ջ����������
    len=s.length();
    for(i=j=0;i<=len;++i){
        if(isalnum(s[i])) c[j++]=s[i];  ///����ǲ�����ֱ�ӵ�����
        else{
            switch(s[i]){
                case '(':
                    exp.push(s[i]);
                    break;
                case ')':
                    while(exp.top()!='(')///���������ţ������ǰ��������֮�������
                    {                    ///�ַ������� !exp.empty()����Ϊ���ųɶ�
                        c[j++]=exp.top();
                        exp.pop();
                    }
                    exp.pop();  ///�����ų�ջ
                    break;
                case '+':
                case '-':
                case '*':
                    while(!exp.empty()&&m[s[i]]<=m[exp.top()]){
                        c[j++]=exp.top();  ///���ȼ���ĳ�ջ
                        exp.pop();
                    }
                    exp.push(s[i]);///�ѵ�ǰ�������ջ
            }
        }
    }
    while(!exp.empty()){  ///���ʣ����������'!'��д�˾������
        c[j++]=exp.top();
        exp.pop();
    }
    c[j]='\0';
    string temp=c;  ///��ת��Ϊstring��
    return temp;
}
int calculate(string r)///�����׺���ʽ��ֵ����ĸ����ASC����
{
    int i,len,a,b;
    stack<int> cal;
    len=r.length();
    for(i=0;i<len;++i){
        if(isalnum(r[i])) {
            if(isdigit(r[i])) cal.push(r[i]-'0');
            else cal.push(r[i]);
        }
        else{///�������������ջ������������������ջ
            a=cal.top();
            cal.pop();
            b=cal.top();
            cal.pop();
            switch(r[i]){
                case '+':
                    cal.push(b+a);
                    break;
                case '-':
                    cal.push(b-a);
                    break;
                case '*':
                    cal.push(b*a);
            }
        }
    }
    return cal.top(); ///ջ��Ԫ�ؾ������յļ�����
}
int main()
{
    int T;
    m['(']=0;
    m['+']=m['-']=1;
    m['*']=2;
    cin>>T;
    cin.get();///����һ���س�
    while(T--){
        getline(cin,s1);
        getline(cin,s2);
        r1=transform(s1);
        r2=transform(s2);
        if(calculate(r1)==calculate(r2)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
