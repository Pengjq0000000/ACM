#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
unsigned LL id[maxn], sum[maxn], want[maxn];
int n, a[maxn], ans;
vector<int>pos;
void deal()
{
    pos.clear();
    for (int i = 1; i <= n; i++) 
    {
        sum[i] = sum[i - 1] ^ id[a[i]];
        if (a[i] == 1) {pos.pb(i); ans = max(ans, 1);}
    }
    for (int st : pos)
    {
        int len = 1;
        for (int r = st + 1; r <= n && a[r] != 1; r++)
        {
            len = max(len, a[r]);
            int l = r - len + 1;
            if (l > 0 && (sum[r] ^ sum[l - 1]) == want[len]) ans = max(ans, len);
        }
    }
}
int random(int x) {return rand() % x + 1;}
int main()
{
    srand((unsigned)time(0));
	int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n); 
        for (int i = 1; i <= n; i++) 
        {
            scanf("%d", &a[i]);
            id[i] = (unsigned LL)((rand() << 16) | rand());
            want[i] = want[i - 1] ^ id[i];
        }
        ans = 0;
        deal();
        for (int i = 1; i <= n / 2; i++) swap(a[i], a[n + 1 - i]);
        deal();
        printf("%d\n", ans);
    }
	return 0;
}
