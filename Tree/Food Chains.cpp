///������ ������ץס�� ���� ���ڲ��鼯Ӧ��
///��Ҫ�Լ��Ƶ������ƹ�ϵ
///��ϸhttp://www.cnblogs.com/dongsheng/archive/2013/06/12/3133188.html
///--------------------------------------------------------------------

#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;

int pre[50005];
int vis[50005]={0};
int n, k, ans=0;

//���µĲ������Ƚ���ǰ�����������������Ȼ������������ڵĹ�ϵ
//��ǰ�ڵ�x����ڵ�r�Ĺ�ϵ���µķ�����
///    (x���丸��ڵĹ�ϵ+�丸��ڵĹ�ϵ�����ڵĹ�ϵ)%3
//�����ڸ��½ڵ�x������֮ǰ��Ҫ�����丸�ڵ�����ݣ�����findΪʲô��ɵݹ麯����ԭ��
//����µĴ����ǴӸ��ڵ㿪ʼ���£�ʼ�յ���ǰ���x�ĸ���ڡ�
int find(int x)
{
    if(x != pre[x]){
        int r = pre[x];
        pre[x] = find(pre[x]);
        //���µ�ǰ��������ڵĹ�ϵ����x->x����x��->�����Ĺ�ϵʧ��x->�����Ĺ�ϵ
        //��������֮ǰ��������丸��������ڵĹ�ϵ
        vis[x] = (vis[x]+vis[r])%3;
    }
    return pre[x];
}

void init(int *x,int a)
{
    for(int i=0;i<a;i++)
        x[i] = i;
}

int main()
{
    cin>>n>>k;
    init(pre, n);
    for(int i=0, d,a,b;i<k;i++){
        scanf("%d%d%d",&d,&a,&b);
        if(a>n || b>n){ans++; continue;}
        if(d==2 && a==b){ans++; continue;}
        int fa=find(a), fb=find(b);
        if(fa == fb){
            if(d==1 && vis[a]!=vis[b]) ans++;
            //�������ͬ�࣬����x��y�Ĺ�ϵ֮��x��Ը���ڵĹ�ϵ(x��->y,y->x(��3-(d-1)=2).��x��->x)Ӧ���ǲ����
            //����d=2��ʾx - y = 2-1=1;��y->x=3-(x->y)=3-1=2;
            if(d==2 && vis[a]!=(vis[b] + 3-1)%3) ans++;
        }
        else{
            pre[fb] = fa;
            //(d-1)Ϊx��y�Ĺ�ϵ��3-relation[y]��y��y�ĸ���ڵĹ�ϵ��ע�ⷽ��relation[x]����������x�Ĺ�ϵ
            //x��->x,x->y,y->y������x��->y��
            vis[fb] = (vis[a] + d-1 + 3-vis[b])%3;///ע������ֻ���µ���fy����ڸ��Ĺ�ϵ
        }

    }
    cout<<ans<<endl;
    return 0;
}
