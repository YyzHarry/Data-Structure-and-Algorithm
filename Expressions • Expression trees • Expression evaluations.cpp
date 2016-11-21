#include<iostream>
#include<string.h>
#include<stack>
#include<map>
#include<math.h>
#include<memory.h>
using namespace std;

const int row=51, col=1000;
int rollend[51];
int layer=0;
char src[row][col];

string str, tmp;
map<char,int> cmp;
int alp[27]={0};

struct Treenode
{
    char s;
    Treenode *left, *right;
    Treenode() {left=NULL; right=NULL;}
    Treenode(char s_):s(s_) {left=NULL; right=NULL;}
};

void buildtree(string str,Treenode* &root)
{
    stack<Treenode *> p;
    for(int i=0;i<str.length();i++){
        if(isalnum(str[i])){
            root = new Treenode(str[i]);
            p.push(root);
        }
        else{
            root = new Treenode(str[i]);
            root->right = p.top();
            p.pop();
            root->left = p.top();
            p.pop();
            p.push(root);
        }
    }
}

string trans(string s)
{
    stack<char> p;
    int len=s.length(), j=0;
    char c[51];
    for(int i=0;i<len;i++){
        if(isalnum(s[i]))
            c[j++] = s[i];
        else if(s[i] == '(')
            p.push(s[i]);
        else if(s[i] == ')'){
            while(p.top() != '('){
                c[j++] = p.top();
                p.pop();
            }
            p.pop();
        }
        else{
            while(!p.empty() && cmp[s[i]]<=cmp[p.top()]){
                c[j++] = p.top();
                p.pop();
            }
            p.push(s[i]);
        }
    }
    while(!p.empty()){
        c[j++] = p.top();
        p.pop();
    }
    c[j] = '\0';
    return string(c);
}

int treelayer(Treenode* root)
{
    int left,right;
    if(!root) return 0;
    left = treelayer(root->left);
    right = treelayer(root->right);
    return left>right? left+1:right+1;
}

void print(Treenode *root,int rootx,int rooty)
{
    if(!root) return;
    src[rootx][rooty] = root->s;
    if(root->left){
        src[rootx+1][rooty-1] = '/';
        int level = (rootx+1)/2;
        int d = pow(2,layer-1-level);
        print(root->left,rootx+2,rooty-d);
    }
    if(root->right){
        src[rootx+1][rooty+1] = '\\';
        int level = (rootx+1)/2;
        int d = pow(2,layer-1-level);
        print(root->right,rootx+2,rooty+d);
    }
    return ;
}

int compute(string s)
{
    stack<int> p;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(isalnum(s[i]))
            p.push(alp[s[i]-'a']);
        else{
            int a = p.top();
            p.pop();
            int b = p.top();
            p.pop();
            switch(s[i]){
                case '+':
                    p.push(b+a);
                    break;
                case '-':
                    p.push(b-a);
                    break;
                case '*':
                    p.push(b*a);
                    break;
                case '/':
                    p.push(b/a);
            }
        }
    }
    return p.top();
}

int main()
{
    int n, t;
    char l;
    cmp['(']=0, cmp['+']=cmp['-']=1, cmp['*']=cmp['/']=2;
    cin>>str>>n;
    while(n--){
        cin>>l>>t;
        alp[l-'a'] = t;
    }
    tmp = trans(str);
    cout<<tmp<<endl;

    Treenode *root = NULL;
    buildtree(tmp,root);

    memset(src,' ',sizeof(src));
    layer = treelayer(root);

    print(root,1,pow(2,layer-1));

    int effective_layer = 0;
    for(int i=1;i<=row;i++){
        int j=col-1;
        while(src[i][j]==' ' && j>0)
            j--;
        if(j > 0){
            effective_layer++;
            rollend[i] = j;
        }
        else break;
    }
    for(int i=1;i<=effective_layer;i++){
        for(int j=1;j<=rollend[i];j++)
            cout<<src[i][j];
        cout<<endl;
    }

    cout<<compute(tmp)<<endl;
    return 0;
}
