#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

const int N=105, INFINITE=0xfffff;
struct point
{
	int x, y;
}p[N];

struct edge
{
	int from, to;
	double cost;
}e[N*N];

double inw[N];
int vis[N], id[N], pre[N];

double Directed_MST(int root, int NV, int NE)
{
	double ret=0;
	while(1){
		for(int i=0; i<NV; ++i)	inw[i]=INFINITE;
		for(int i=0; i<NE; ++i){
			int from=e[i].from;
			int to=e[i].to;
			if (e[i].cost<inw[to] && from!=to){
				inw[to]=e[i].cost;
				pre[to]=from;
			}
		}
		for (int i=0; i<NV; ++i){
			if(i==root)	continue;
			if(inw[i]==INFINITE) return -1;
		}
		for (int i=0; i<NV; ++i){
			vis[i]=-1;
			id[i]=-1;
		}

		int newidx=0;
		inw[root]=0;
		for (int i=0; i<NV; ++i){
			ret+=inw[i];
			int v=i;
			while (vis[v]!=i && id[v]==-1 && v!=root){
				vis[v]=i;
				v=pre[v];
			}
			if (v!=root && id[v]==-1){
				for (int u=pre[v]; u!=v; u=pre[u])
                    id[u]=newidx;
				id[v]=newidx;
				++newidx;
			}
		}
		if(newidx==0) break;
		for (int i=0; i<NV; ++i)
			if(id[i]==-1) id[i]=newidx++;

		for (int i=0; i<NE; ++i){
			int to=e[i].to;
			e[i].from=id[e[i].from];
			e[i].to=id[e[i].to];
			if(e[i].from!=e[i].to)
				e[i].cost -= inw[to];
		}
		NV=newidx;
		root=id[root];
	}
	return ret;
}

double calcdist(int a, int b)
{
	return sqrt(pow(p[a].x - p[b].x,2)+pow(p[a].y - p[b].y,2));
}

int main()
{
	int n, m, from, to;
	double ans;
	while(cin>>n>>m)
	{
		for (int i=0;i<n;++i)
			cin>>p[i].x>>p[i].y;

		for (int i=0; i<m; ++i){
			cin>>from>>to;
			e[i].from=from-1;
			e[i].to=to-1;
			e[i].cost=calcdist(from-1, to-1);
		}
		ans=Directed_MST(0, n, m);
		if(ans==-1) printf("NO\n");
		else printf("%.2f\n", ans);
	}
	return 0;
}
