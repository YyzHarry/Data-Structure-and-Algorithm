#include<iostream>
#include<stdio.h>
#include<math.h>
#include<memory.h>
using namespace std;

double src[201][201];
double x[201], y[201];
double wei[201];
int vis[201];

int main()
{
    int n, cases=1;
    while(cin>>n && n!=0){
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) cin>>x[i]>>y[i];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                src[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        for(int i=0;i<n;i++)
            wei[i] = src[0][i];

        for(int i=0;i<n;i++){
            double Max=65535;
            int v;
            for(int j=0;j<n;j++)
                if(!vis[j] && wei[j]<Max){
                    Max = wei[j];
                    v = j;
                }
            vis[v]=1;
            for(int j=0;j<n;j++)
                if(!vis[j] && wei[j]>max(wei[v],src[v][j]))
                    wei[j] = max(wei[v],src[v][j]);
        }
        cout<<"Scenario #"<<cases++<<endl;
        printf("Frog Distance = %.3f\n\n",wei[1]);
    }
    return 0;
}
