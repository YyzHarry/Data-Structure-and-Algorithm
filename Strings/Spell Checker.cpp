#include <stdio.h>
#include <string.h>

int lend[10001];
char Dt[10001][20],Word[20];
int Find(int a)
{
    int i;
    int wordlen = strlen(Word);
    if(lend[a] == wordlen){
        for(i=0;i<lend[a]&&Dt[a][i] == Word[i];i++);
        for(i++;i<lend[a]&&Dt[a][i] == Word[i];i++);
        if(i == wordlen) return 1;
    }
    if(lend[a]-wordlen == 1){
        for(i=0;i<wordlen&&Dt[a][i] == Word[i];i++);
        for(;i<wordlen&&Dt[a][i+1] == Word[i];i++);
        if(i == wordlen) return 1;
    }
    if(lend[a]-wordlen == -1){
        for(i=0;i<lend[a]&&Dt[a][i] == Word[i];i++);
        for(;i<lend[a]&&Dt[a][i] == Word[i+1];i++);
        if(i == lend[a]) return 1;
    }
    return 0;
}

int main()
{
    int n=0,i;
	scanf("%s",Dt[n]);
	while(Dt[n][0] != '#'){
        lend[n] = strlen(Dt[n]);
        scanf("%s",&Dt[++n][0]);
	}
	scanf("%s",Word);
	while(Word[0] != '#'){
        int len = strlen(Word);
        for(i=0;i<n;i++)
        if(!strcmp(Word,Dt[i])) ///can be simpler
            {printf("%s is correct\n",Dt[i]); break;}
        if(i == n){
            printf("%s:",Word);
            for(i=0;i<n;i++)
                if(Find(i)) printf(" %s",Dt[i]);
            printf("\n");
        }
        scanf("%s",Word);
	}
	return 0;
}
