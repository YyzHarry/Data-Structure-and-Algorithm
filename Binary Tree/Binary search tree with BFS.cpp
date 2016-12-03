#include<iostream>
#include<queue>
using namespace std;

int n, cnt=1, flag, t=0;

struct Treenode
{
    Treenode* left, *right;
    int num;
    Treenode() {}
    Treenode(int n):num(n) {left=NULL; right=NULL;}
};

void buildtree(Treenode* root,int n)
{
    Treenode* newroot = new Treenode(n);
    Treenode* pointer = root;
    while(pointer){
        if(pointer->num == n) {flag=0; return;}
        else if(pointer->num > n){
            if(!pointer->left){
                pointer->left = newroot; return;
            }
            else pointer = pointer->left;
        }
        else{
            if(!pointer->right){
                pointer->right = newroot; return;
            }
            else pointer = pointer->right;
        }
    }
}

int main()
{
    cin>>n;
    Treenode* root = new Treenode(n);
    while(cin>>n){
        flag=1;
        buildtree(root,n);
        if(flag) cnt++;
        if(cin.get()!=' ') break;
    }
    queue<Treenode* > q;
    q.push(root);
    while(!q.empty()){
        root = q.front();
        q.pop();
        t++;
        cout<<root->num;
        if(t != cnt) cout<<" ";
        if(root->left) q.push(root->left);
        if(root->right) q.push(root->right);
    }
    return 0;
}
