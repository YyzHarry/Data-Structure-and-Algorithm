#include<iostream>
using namespace std;

int currentsize;
int heap[100001];
void siftdown(int position)///��position���µ���
{
    int i = position;
    int j = 2*position+1;
    int tmp = heap[i];  ///���游�ڵ�
    while(j < currentsize){
        if(j<currentsize-1 && heap[j+1]<heap[j]) ///ѡ�����Һ����и�С���Ǹ�
            j++;
        if(tmp > heap[j]){
            heap[i] = heap[j];
            i = j;
            j = 2*j+1;
        }
        else break;  ///������˳��������
    }
    heap[i] = tmp;
    return ;
}

void insert(int num) ///������Ԫ��
{
    heap[currentsize++] = num;
    return ;
}

void del() ///ɾ����СԪ��
{
    heap[0] = heap[currentsize-1];
    currentsize--;
    siftdown(0);
    return ;
}

void build() ///����С��
{
    for(int i=currentsize/2-1;i>=0;i--)
        siftdown(i);
    return ;
}

int main()
{
    int k, n, a, b;
    cin>>k;
    while(k--){
        cin>>n;
        currentsize=0;
        while(n--){
            cin>>a;
            if(a == 1){
                cin>>b;
                insert(b);
            }
            else{
                build(); ///ÿ��Ҫ�����СԪ��ʱ����ά����
                cout<<heap[0]<<endl;
                del();
            }
        }
    }
    return 0;
}
