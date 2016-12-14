#include<iostream>
#include<string.h>
using namespace std;

char s[105], tmp;
int cnt;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    TreeNode() {left = NULL; right = NULL;}
    char s;
};

void build(TreeNode* &root,int depth,char s1)
{
    if(s[0] == '0') return;
    root = new TreeNode;
    root->s = s1;

    cin>>s;
    if(s[0] == '0') return;

    cnt=0;
    for(int i=0;i<strlen(s);i++)
        if(s[i] == '-') cnt++;

    tmp = s[strlen(s)-1];

    if(cnt == depth+1) build(root->left,depth+1,tmp);
    if(cnt <= depth) return;
    build(root->right,depth+1,tmp);
}

void pre(TreeNode* root)
{
    if(root){
        if(root->s != '*') cout<<root->s;
        pre(root->left);
        pre(root->right);
    }
}
void mid(TreeNode* root)
{
    if(root){
        mid(root->left);
        if(root->s != '*') cout<<root->s;
        mid(root->right);
    }
}
void las(TreeNode* root)
{
    if(root){
        las(root->left);
        las(root->right);
        if(root->s != '*') cout<<root->s;
    }
}

int main()
{
    int n; cin>>n;
    while(n--){
        TreeNode* root = NULL;
        cin>>s;
        build(root,0,s[0]);
        pre(root); cout<<endl;
        las(root); cout<<endl;
        mid(root); cout<<endl;
        cout<<endl;
    }
    return 0;
}
