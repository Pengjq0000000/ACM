#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
int ans[3];
char s[107];
int table[30]={0,2,1,8,4,2,1,4,2,1,8,4,2,1,4,2,1,8,4,2,1};
int main()
{
    int T,cas=0;scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);int L=strlen(s);
        int cnt=0,now=0,tmp=0;
        int flg=0;
        for (int i=0;i<L;i++)
        {
            if (s[i]=='(') flg=0;
            if (s[i]=='*') flg=1;
            if (s[i]==')')
            {
                cnt++;
                tmp+=flg*table[cnt];
                if (cnt==2||cnt==9||cnt==16) tmp*=10;
            }
            if (cnt==6 && now==0) {ans[now]=tmp;now++;tmp=0;}
            if (cnt==13 && now==1) {ans[now]=tmp;now++;tmp=0;}
            if (cnt==20 && now==2) {ans[now]=tmp;tmp=0;}
        }
        printf("Case %d: ",++cas);
        for (int i=0;i<3;i++)
        {
            if (ans[i]<10) printf("0");
            printf("%d",ans[i]);
            if (i<2) printf(":");
        }
        printf("\n");
    }
    return 0;
}

