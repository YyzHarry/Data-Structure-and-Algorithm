#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 110;

struct node
{
	int v,l,t;
	struct node *next;
}edge[maxn];

int n,m,k;
int vis[maxn];
int ans;

void dfs(int u, int cost, int len)
{
	for(struct node *tmp = edge[u].next; tmp!= NULL; tmp = tmp->next){
		int v = tmp->v;
		if(!vis[v] && cost + tmp->t <= k && (len + tmp->l < ans || ans == -1)){
			if(v == n){
				ans = len + tmp->l;
				continue;
			}
			vis[v] = 1;
			dfs(v, cost + tmp->t, len + tmp->l);
			vis[v] = 0;
		}
	}
}

int main()
{
	int s,d,l,t;
	scanf("%d %d %d",&k,&n,&m);
    for(int i = 1; i <= n; i++)
        edge[i].next = NULL;

    for(int i = 1; i <= m; i++){
        scanf("%d %d %d %d",&s,&d,&l,&t);
        struct node *tmp = new node;
        tmp->v = d;
        tmp->l = l;
        tmp->t = t;
        tmp->next = edge[s].next;
        edge[s].next = tmp;
    }
    ans = INF;
    memset(vis,0,sizeof(vis));
    vis[1] = 1;
    dfs(1,0,0);

    if(ans == INF)
        printf("-1\n");
    else printf("%d\n",ans);
	return 0;
}
