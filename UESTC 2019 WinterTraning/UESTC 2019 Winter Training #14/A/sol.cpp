#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char s[10007];
int dd,mm,yy,nowd,nowm,nowy;
int st,ed;
void deal(char *s)
{
    dd=0;for (int i=0;i<2;i++) dd=dd*10+s[i]-'0';
    mm=0;for (int i=3;i<5;i++) mm=mm*10+s[i]-'0';
    yy=0;for (int i=6;i<8;i++) yy=yy*10+s[i]-'0';
    st=0;
    for (int i=1;i<mm;i++) st+=day[i];
    st+=(yy%4)*365+(yy/4)*(365*3+366)+dd+(mm>2&&yy%4==0);
}

void deall(char *s)
{
    nowd=0;for (int i=0;i<2;i++) nowd=nowd*10+s[i]-'0';
    nowm=0;for (int i=3;i<5;i++) nowm=nowm*10+s[i]-'0';
    nowy=0;for (int i=6;i<8;i++) nowy=nowy*10+s[i]-'0';
    ed=0;
    for (int i=1;i<nowm;i++) ed+=day[i];
    ed+=(nowy%4)*365+(nowy/4)*(365*3+366)+nowd+(nowm>2&&nowy%4==0);
}

int main()
{
    int x;scanf("%d",&x);getchar();
    int L;
    int tot=0;
    while (1)
    {
        L=0;while ((s[L]=getchar())!=EOF && s[L]!='\n') L++;
        if (L==0) break;
        if (L==8)
        {
        	cout<<endl;
            printf("Current date ");
            for (int i=0;i<L;i++) printf("%c",s[i]);cout<<endl;
            deal(s);tot=0;
            continue;
        }
        deall(s);
        //printf("%d %d\n",st,ed);
        int flg=0;if (st-ed+1>=180 && s[L-1]=='A') {tot++;flg=1;}
        if (flg) cout<<"Accepted ";else cout<<"Denied ";
        for (int i=9;i<L-2;i++) printf("%c",s[i]);
        if (flg) cout<<" "<<tot<<endl;else cout<<endl;
    }
    return 0;
}


/*
2
25/09/08
12/02/08 Juan Jimenez A
06/08/08 Martha Martinez B
09/03/08 Raul Ramirez A
03/10/08
20/08/08 Maria Gonzalez A

*/
