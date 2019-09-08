#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
/*------------------------------------------------------------------------*/

// KMP
const int maxn = 1e5+7;

struct Kmp
{
    int nex[maxn], n, m;
    void GetNext(char *p)
    {
        m = strlen(p);
        for (int i = 0 ; i <= m; i++) nex[i] = 0;
        nex[0] = -1;
        int k = -1, j = 0;
        while (j < m)
        {
            if (k == -1 || p[j] == p[k]) nex[++j] = ++k;
            else k = nex[k];
        }
    }
    int match(char *s, char *p)
    {
        GetNext(p);
        n = strlen(s), m = strlen(p);
        int i = 0, j = 0, cnt = 0;
        while (i < n && j < m)
        {
            if (j == -1 || s[i] == p[j]) i++, j++;
            else j = nex[j];
            if (j == m) //successfully match
            {
                j = nex[j]; // cross(s=aaaa p=aa cnt=3)
                //j=0;    // non-cross(s=aaaa p=aa cnt=2)
                // cout << i << endl; 
                // match point:the i-th(starting from 1) of s
                cnt++;// match counts
            }
        }
        return cnt;
    }
}KMP;

/*------------------------------------------------------------------------*/
char s[maxn], t[maxn];
int main()
{
	scanf("%s", t);
    int lt = strlen(t);
    int q; scanf("%d", &q);
    while (q--)
    {
        scanf("%s", s); int ls = strlen(s);
        if (lt > ls)
        {
            if (KMP.match(t, s) > 0) puts("my child!");
            else puts("oh, child!");
        }
        else if (ls > lt)
        {
            if (KMP.match(s, t) > 0) puts("my teacher!");
            else puts("senior!");
        }
        else 
        {
            if (KMP.match(s, t)) puts("jntm!");
            else puts("friend!");
        }
    }
	return 0;
}
