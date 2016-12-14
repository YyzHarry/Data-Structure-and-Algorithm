#include<iostream>
using namespace std;
int lasnum=0;
struct TreeNode{
    int num;
    struct TreeNode *left, *right;
};

TreeNode* buildtree(int mid[],int las[],int midstart,int midend,int lasstart,int lasend)
{
    //if(midstart > midend) return NULL;
    TreeNode *root = new TreeNode;
    root->num = las[lasend];
    root->left=NULL; root->right=NULL;
    if(midstart != midend){
        int divide = -1;
        for(int i=midstart;i<=midend;i++)
            if(mid[i] == las[lasend]) {divide = i; break;}
        if(divide == -1) return NULL;
        root->left = buildtree(mid,las,midstart,divide-1,lasstart,lasstart+divide-midstart-1);
        root->right = buildtree(mid,las,divide+1,midend,lasend+divide-midend,lasend-1);
    }
    return root;
}

void getlast(TreeNode *root)
{
    if(root != NULL){
        cout<<root->num;
        if(lasnum>1) {lasnum--; cout<<' ';}
        getlast(root->left);
        getlast(root->right);
    }
}

int main()
{
    int mid[65536],las[65536];
    while(cin>>mid[lasnum++])
        if(cin.get()!=' ') break;
    lasnum=0;
    while(cin>>las[lasnum++])
        if(cin.get()!=' ') break;
    TreeNode * root = buildtree(mid,las,0,lasnum-1,0,lasnum-1);
    getlast(root);
    return 0;
}
