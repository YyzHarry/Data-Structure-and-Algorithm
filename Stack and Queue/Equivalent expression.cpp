#include<map>
#include<stack>
#include<iostream>
using namespace std;
map<char,int> m;  ///从字符映射到数字
string s1,s2,r1,r2;
string transform(string s)///把表达式转化为后缀表达式方便计算
{
    int i,j,len;
    char c[81];
    stack<char> exp;  ///定义一个字符栈，存放运算符
    len=s.length();
    for(i=j=0;i<=len;++i){
        if(isalnum(s[i])) c[j++]=s[i];  ///如果是操作数直接到数组
        else{
            switch(s[i]){
                case '(':
                    exp.push(s[i]);
                    break;
                case ')':
                    while(exp.top()!='(')///碰到右括号，输出与前面左括号之间的所有
                    {                    ///字符，无需 !exp.empty()，因为括号成对
                        c[j++]=exp.top();
                        exp.pop();
                    }
                    exp.pop();  ///左括号出栈
                    break;
                case '+':
                case '-':
                case '*':
                    while(!exp.empty()&&m[s[i]]<=m[exp.top()]){
                        c[j++]=exp.top();  ///优先级大的出栈
                        exp.pop();
                    }
                    exp.push(s[i]);///把当前运算符入栈
            }
        }
    }
    while(!exp.empty()){  ///输出剩余的运算符，'!'忘写了纠结半天
        c[j++]=exp.top();
        exp.pop();
    }
    c[j]='\0';
    string temp=c;  ///需转化为string型
    return temp;
}
int calculate(string r)///计算后缀表达式的值，字母用其ASC代替
{
    int i,len,a,b;
    stack<int> cal;
    len=r.length();
    for(i=0;i<len;++i){
        if(isalnum(r[i])) {
            if(isdigit(r[i])) cal.push(r[i]-'0');
            else cal.push(r[i]);
        }
        else{///碰到运算符，出栈两个数，运算结果再入栈
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
    return cal.top(); ///栈顶元素就是最终的计算结果
}
int main()
{
    int T;
    m['(']=0;
    m['+']=m['-']=1;
    m['*']=2;
    cin>>T;
    cin.get();///跳过一个回车
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
