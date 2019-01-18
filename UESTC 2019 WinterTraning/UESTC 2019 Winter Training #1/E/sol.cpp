#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 1e6+7;
struct node
{
    int next[26],cnt;
}Tree[maxn];

int size=1;
char ans[maxn],s[maxn];

void Add_string(char *s)
{
    int len=0;
    int L=strlen(s);
    int now=0,flg=0;
    for (int i=0;i<L;i++)
    {
        int c=s[i]-'a';
        if (!flg) ans[len++]=s[i];
        if (!Tree[now].next[c])
        {
            flg=1;
            Tree[now].next[c]=size++;
        }
        now=Tree[now].next[c];
    }
    Tree[now].cnt++;
    for (int i=0;i<len;i++) printf("%c",ans[i]);
    if (Tree[now].cnt>1) printf(" %d",Tree[now].cnt);
    printf("\n");
}

int main()
{
    int n;scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s);
        Add_string(s);
    }
    return 0;
}
