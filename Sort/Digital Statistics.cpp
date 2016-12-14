#include<iostream>
#include<stdio.h>
using namespace std;

struct Link
{
    int num;
    int cnt;
    Link *next;
    Link() {next = NULL;}
};

void Linkinsert(Link *phead,int n)
{
    Link *p = new Link;
    p->num = n;
    p->cnt = 1;
    p->next = phead->next;
    phead->next = p;
}

Link * get(Link* phead,int a)
{
    Link *p = phead->next;
    while(p && p->num != a)
        p = p->next;
    return p;
}

void sort(Link* phead)
{
    Link *p, *q;
    int tmp1,tmp2;
    for(p = phead->next;p!=NULL;p=p->next)
        for(q = phead->next;q->next!=NULL;q=q->next){
            if(q->num > q->next->num){
                tmp1 = q->num;
                tmp2 = q->cnt;
                q->num = q->next->num;
                q->next->num = tmp1;
                q->cnt = q->next->cnt;
                q->next->cnt = tmp2;
            }
        }
}

int main()
{
    int n, a;
    cin>>n;
    Link *phead = new Link, *p;
    while(n--){
        scanf("%d",&a);
        if((p = get(phead,a)) != NULL)
            p->cnt++;
        else Linkinsert(phead,a);
    }
    sort(phead);
    for(p=phead->next;p!=NULL;p=p->next)
        printf("%d %d\n",p->num,p->cnt);
    return 0;
}
