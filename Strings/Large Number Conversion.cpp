#include <stdio.h>
#include <string.h>
char str[1000];
int start[1000],ans[1000],res[1000]; //���������̣�����

const int oldBase = 10;
const int newBase = 2;

void change()
{
    int i,len = strlen(str);
    start[0] = len;
    for(i=1;i<= len;i++)
        if(str[i-1] >= '0' && str[i-1] <= '9')
            start[i] = str[i-1] - '0';
}

void solve()
{
    memset(res,0,sizeof(res));//������ʼ��Ϊ��
    int y,i,j;
    //ģnȡ�෨��(�������������Ϊ��λ������Ϊ��λ)
    while(start[0] >= 1)
    {//ֻҪ��������Ȼ���ڵ���1���Ǿͼ�����ģ2ȡ�ࡱ
        y=0;
        i=1;
        ans[0]=start[0];

        while(i <= start[0])
        {
            y = y * oldBase + start[i];
            ans[i++] = y/newBase;
            y %= newBase;
        }
        res[++res[0]] = y;//��һ������õ�������
        i = 1;
        //�ҵ���һ���̵���ʼ��
        while((i<=ans[0]) && (ans[i]==0)) i++;
        //�����һ��ʹ�õı�����
        memset(start,0,sizeof(start));
        //���ֵõ����̱�Ϊ��һ�ֵı�����
        for(j = i;j <= ans[0];j++)
            start[++start[0]] = ans[j];
        memset(ans,0,sizeof(ans)); //�����һ�ֵ��̣�Ϊ��һ��������׼��
    }
}

void output()
{//�Ӹ�λ����λ�������
    int i;
    for(i = res[0];i >= 1;--i)
    {
        printf("%d",res[i]);
    }
    printf("\n");
}

int main()
{
    scanf("%s",str);
    change();
    solve();
    output();
    return 0;
}
