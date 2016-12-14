#include<iostream>
#include<stdio.h>
using namespace std;

struct Link
{
    int num,pow;
    struct Link *next;
};

void Linkinsert(Link *phead,int a,int b)
{
    Link *p = new Link;
    p->num = a;
    p->pow = b;
    p->next = phead->next;
    phead->next = p;
}

Link * get(Link *phead ,int a)  ///此处返回指针
{
    Link *p = phead->next;
    while(p && p->pow != a)
        p = p-> next;
    return p;
}

void sort(Link *phead)
{
    Link *p ,*q;
    int tmp1,tmp2;
    for(p = phead->next;p!=NULL;p=p->next)
        for(q = phead->next;q->next!=NULL;q=q->next) ///注意冒泡排序的方式，此处全排序
            if(q->pow < q->next->pow){
                tmp1 = q->num;
                tmp2 = q->pow;
                q->num = q->next->num;
                q->pow = q->next->pow;
                q->next->num = tmp1;
                q->next->pow = tmp2;
            }
}

int main()
{
    int n;
    cin>>n;
    while(n--){
        Link *phead =new Link, *p, *q;
        phead ->next =NULL;  ///head为空
        int m=1;
        while(m <= 2){
            int a,b;
            while(scanf("%d%d",&a,&b)){
                if(b < 0) break;
                if( (p=get(phead,b))!= NULL ) p->num += a;
                else Linkinsert(phead, a, b);
            }
            m++;
        }
        sort(phead);
        for(p=phead->next;p != NULL;p=p->next) ///p要到最后
            if(p->num != 0) cout<<"[ "<<p->num<<" "<<p->pow<<" ] ";
        cout<<endl;
        for(p=phead;p != NULL;p=p->next){
            q = p;
            delete q;
        }
    }
    return 0;
}
