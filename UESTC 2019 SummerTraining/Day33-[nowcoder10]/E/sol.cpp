#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pii pair<int, int>
#define fir first
#define sec second
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
long long aa;bool bb;char ch;
long long scan()
{
    while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
    ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
    while(ch=getchar(),(ch>='0'&&ch<='9'))
        aa=aa*10+ch-48;
    return (bb?(-aa):(aa));
}
const int maxn = 1e6 + 7;
int n, k;
vector<pii>p;
vector<pii> d;
void dfs(int x, int y, int k, vector<pii> &pp)
{
    if (k == 0)
    {
        printf("%d %d\n", x, y);
        return;
    }
    int len = (1 << (k - 1));
    pii c[5];
    for (int j = 1; j <= 4; j++)
    {
        c[j].fir = x + d[j - 1].fir * len;
        c[j].sec = y + d[j - 1].sec * len;
    }
    //for (int j = 1; j <= 4; j++)
        //printf("C[%d]: %d %d\n", j, c[j].fir, c[j].sec);
    vector<pii> v[5];
    for (pii x : pp)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (c[j].fir <= x.fir && x.fir < c[j].fir + len
                && c[j].sec <= x.sec && x.sec < c[j].sec + len)
            {
                v[j].pb(x);
            }
        }
    }
    for (int j = 1; j <= 4; j++)
    {
        //for (pii x : v[j]) printf("j=%d DEBUG:%d %d\n", j, x.fir, x.sec);
        if (v[j].size())
        {
            if (j == 1)
            {
                swap(d[1], d[3]);
                dfs(c[j].fir, c[j].sec, k - 1, v[j]);
                swap(d[1], d[3]);
            }
            else if (j == 4)
            {
                swap(d[0], d[2]);
                dfs(c[j].fir, c[j].sec, k - 1, v[j]);
                swap(d[0], d[2]);
            }
            else dfs(c[j].fir, c[j].sec, k - 1, v[j]);
        }
    }
}

int main()
{
	n = scan(); k = scan();
    for (int i = 1; i <= n; i++)
    {
        int x = scan(), y = scan();
        p.pb(make_pair(x, y));
    }
    d.pb(make_pair(0, 0));
    d.pb(make_pair(1, 0));
    d.pb(make_pair(1, 1));
    d.pb(make_pair(0, 1));
    dfs(1, 1, k, p);
	return 0;
}
