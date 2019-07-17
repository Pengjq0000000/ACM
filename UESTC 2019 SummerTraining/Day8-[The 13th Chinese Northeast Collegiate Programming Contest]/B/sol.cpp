#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define int long long
using namespace std;

int T;
int n,m;
struct candy
{
    long long v;
    int r,c,l;// rank color limit
}a[100005];
int lim[100005];
vector<long long>v[100005],s[100005];
vector<int>l[100005],r[100005];
long long sum;
long long son,mom;
bool cmp1(candy a,candy b){return a.v>b.v;}
bool cmp2(candy a,candy b){return a.l<b.l;}
void ini()
{
    for(int i=1;i<=n;i++)
        v[i].clear(), l[i].clear();
    for(int i=1;i<=m;i++)
        s[i].clear(), r[i].clear();
    sum=0;
    son=0;
    mom=1;
}
struct temp
{
	int id;
	int l;
	bool friend operator < (temp a,temp b)
	{
		return a.l<b.l;
	}
}tmp[100005];
int srename[100005];
signed main()
{
    scanf("%lld",&T);
	while(T--)
    {
        scanf("%lld%lld",&n,&m);
        ini();
        for(int i=1;i<=m;i++)
        {
            scanf("%lld",&lim[i]);
        	tmp[i].id=i;
        	tmp[i].l=lim[i];
		}
        sort(lim+1,lim+1+m);
        sort(tmp+1,tmp+1+m);
        for(int i=1;i<=m;i++)
        	srename[tmp[i].id]=i;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld",&a[i].v,&a[i].c);
            a[i].c=srename[a[i].c];
            a[i].l=lim[a[i].c];
        }
        sort(a+1,a+1+n,cmp1);
        for(int i=1;i<=n;i++)
        {
            s[a[i].c].push_back(a[i].v);
            a[i].r=s[a[i].c].size();
            r[a[i].c].push_back(a[i].r);
        }
        sort(a+1,a+1+n,cmp2);
        for(int i=1;i<=n;i++)
        {
            v[a[i].r].push_back(a[i].v);
            l[a[i].r].push_back(a[i].l);
        }
        for(int i=1;i<=m;i++)
        {
        	if(lim[i]>s[i].size())
        		s[i].clear(),r[i].clear();
		}
        int now=1;
        while(lim[now]==0&&now<=m) now++;
        for(long long c=1;c<=n;c++)
        {
            while(lim[now]==c&&now<=m)
            {
                for(int i=0;i<s[now].size();i++)
                {
                    if(r[now][i]>=c) break;
                    sum+=s[now][i];
                }
                now++;
            }
            for(int i=0;i<v[c].size();i++)
            {
                if(l[c][i]>c) break;
                sum+=v[c][i];
            }
            if(sum*mom>son*c)
            {
                son=sum;
                mom=c;
            }
        }
        long long g=__gcd(son,mom);
        printf("%lld/%lld\n",son/g,mom/g);
    }
	return 0;
}