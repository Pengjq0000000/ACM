#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 3e6+7;

char s[maxn];
int op[maxn],L,now,ans[maxn];

void dfs(int pos)
{
    if (pos>=L || s[pos]=='?') return;
    op[++now]=op[pos];
    dfs(now);
    op[++now]=op[pos]+(s[pos]=='-');
    dfs(now);
}


int main()
{
    scanf("%s",s);L=strlen(s);
    //op[0]=(s[0]=='-');
    op[0]=0;
    now=0;
    dfs(now);

    int cnt1=0,cnt2=0;
    for (int i=0;i<L;i++)
    {
        if (s[i]=='?')
        {
            ans[i]=1;
            if (op[i]%2==1) cnt1++; // -
            else cnt2++;  // +
        }
    }

    //for (int i=0;i<L;i++) printf("%d ",op[i]);
    //printf("\n");
    int tmp,num;

    //printf("1:%d 2:%d\n",cnt1,cnt2);
    if (cnt1>cnt2)
    {
        tmp=cnt1/cnt2;
        num=cnt1%cnt2;
        for (int i=0;i<L;i++)
        {
            if (s[i]=='?' && op[i]%2==0)
            {
                ans[i]=tmp;
                if (num) num--,ans[i]++;
            }
        }
    }
    else
    {
        tmp=cnt2/cnt1;
        num=cnt2%cnt1;
        for (int i=0;i<L;i++)
        {
            if (s[i]=='?' && op[i]%2==1)
            {
                ans[i]=tmp;
                if (num) num--,ans[i]++;
            }
        }
    }

    for (int i=0;i<L;i++)
        if (s[i]=='?') printf("%d\n",ans[i]);

    return 0;
}

