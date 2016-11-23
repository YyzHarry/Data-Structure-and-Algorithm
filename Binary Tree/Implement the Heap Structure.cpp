#include<iostream>
using namespace std;

int currentsize;
int heap[100001];
void siftdown(int position)///从position向下调整
{
    int i = position;
    int j = 2*position+1;
    int tmp = heap[i];  ///保存父节点
    while(j < currentsize){
        if(j<currentsize-1 && heap[j+1]<heap[j]) ///选择左右孩子中更小的那个
            j++;
        if(tmp > heap[j]){
            heap[i] = heap[j];
            i = j;
            j = 2*j+1;
        }
        else break;  ///堆满足顺序则跳出
    }
    heap[i] = tmp;
    return ;
}

void insert(int num) ///插入新元素
{
    heap[currentsize++] = num;
    return ;
}

void del() ///删除最小元素
{
    heap[0] = heap[currentsize-1];
    currentsize--;
    siftdown(0);
    return ;
}

void build() ///建最小堆
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
                build(); ///每次要输出最小元素时，再维护堆
                cout<<heap[0]<<endl;
                del();
            }
        }
    }
    return 0;
}
