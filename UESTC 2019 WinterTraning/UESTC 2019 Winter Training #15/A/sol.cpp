#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1007;
char t[maxn],s[maxn];
int a[maxn],b[maxn],typea[maxn],typeb[maxn],tota,totb;
void deal(char *s)
{
    int lt=strlen(s);tota=0;
    int i=0;
    while (i<lt)
    {
        while ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') && i<lt) 
        {
            a[++tota]=s[i++];
            typea[tota]=2;
        }
        if (s[i]>='0' && s[i]<='9')
        {
            int tmp=0;
            while (s[i]>='0' && s[i]<='9' && i<lt)
            {
                tmp=tmp*10+s[i]-'0';i++;
            } 
            a[++tota]=tmp;
            typea[tota]=1;       
        }
    }
}

void deall(char *s)
{
    int ls=strlen(s);totb=0;
    int i=0;
    while (i<ls)
    {
        while ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') && i<ls) 
        {
            b[++totb]=s[i++];
            typeb[totb]=2;
        }
        if (s[i]>='0' && s[i]<='9')
        {
            int tmp=0;
            while (s[i]>='0' && s[i]<='9' && i<ls)
            {
                tmp=tmp*10+s[i]-'0';i++;
            } 
            b[++totb]=tmp;
            typeb[totb]=1;       
        }
    }   
}

int check()
{
    int n=min(tota,totb);
    for (int i=1;i<=n;i++)
    {
        if (typea[i]!=typeb[i]) return (typeb[i]<typea[i]);
        if (a[i]!=b[i]) return (b[i]<a[i]);
    }
    return totb<tota;
}


void print()
{
    for (int i=1;i<=totb;i++)
    {
        printf("%d ",i);
        if (typeb[i]==1) printf("%c\n",b[i]);
        else printf("%d\n",b[i]);
    }
}
int main()
{
    int q;scanf("%d",&q);
    scanf("%s",t);deal(t);

    while (q--)
    {
        scanf("%s",s);deall(s);//print();
        if (check()) puts("-");else puts("+");
    }
    return 0;
}

