#include <stdio.h>
#include <string.h>
char str[1000];
int start[1000],ans[1000],res[1000]; //被除数，商，余数

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
    memset(res,0,sizeof(res));//余数初始化为空
    int y,i,j;
    //模n取余法，(总体规律是先余为低位，后余为高位)
    while(start[0] >= 1)
    {//只要被除数仍然大于等于1，那就继续“模2取余”
        y=0;
        i=1;
        ans[0]=start[0];

        while(i <= start[0])
        {
            y = y * oldBase + start[i];
            ans[i++] = y/newBase;
            y %= newBase;
        }
        res[++res[0]] = y;//这一轮运算得到的余数
        i = 1;
        //找到下一轮商的起始处
        while((i<=ans[0]) && (ans[i]==0)) i++;
        //清除这一轮使用的被除数
        memset(start,0,sizeof(start));
        //本轮得到的商变为下一轮的被除数
        for(j = i;j <= ans[0];j++)
            start[++start[0]] = ans[j];
        memset(ans,0,sizeof(ans)); //清除这一轮的商，为下一轮运算做准备
    }
}

void output()
{//从高位到低位逆序输出
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
