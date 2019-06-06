#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int ans[maxn], n, m;
char s[maxn], p[maxn], pp[maxn];
bool can[maxn];
int check(int st)
{
	if (n - st < m) return 0;
	for (int i = 0; i < m; i++) pp[i] = p[i], can[i] = 1;
	for (int i = 0; i < m; i++)
	{
		if (s[i + st] == pp[i]) continue;
		else
		{
			if (can[i]) 
			{
				swap(pp[i], pp[i + 1]);
				if (pp[i] != s[i + st]) return 0;
				can[i] = can[i + 1] = 0;
			}
			else return 0;
		}
	}
	return 1;
}

struct Kmp
{
    int nex[maxn],n,m;
    void GetNext(char *p)
    {
        m=strlen(p);
        memset(nex,0,sizeof(nex));
        nex[0]=-1;
        int k=-1,j=0;
        while (j<m)
        {
            if (k==-1 || p[j]==p[k]) nex[++j]=++k;
            else k=nex[k];
        }
    }
    int match(char *s,char *p)
    {
        n=strlen(s),m=strlen(p);
        int i=0,j=0,cnt=0;
        while (i<n && j<m)
        {
            if (j==-1 || s[i]==p[j]) i++,j++;
            else j=nex[j];
            if (j==m) //successfully match
            {
                j=nex[j]; // cross(s=aaaa p=aa cnt=3)
                //j=0;    // non-cross(s=aaaa p=aa cnt=2)
                ans[i - m] = 1; 
				//printf("match: %d\n", i - m);
                // match point:the i-th(starting from 1) of s
                cnt++;// match counts
            }
        }
        return cnt;
    }
}KMP;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		scanf(" %s", s); scanf(" %s", p);
		for (int i = 0; i < n; i++) ans[i] = 0;
		KMP.GetNext(p);
		KMP.match(s, p);
		for (int i = 0; i < n; i++)
		{
			if (ans[i]) printf("1");
			else printf("%d", check(i));
		}
		puts("");
	}
	return 0;
}
