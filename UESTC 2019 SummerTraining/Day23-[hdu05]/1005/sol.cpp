#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int ans[100], tmp[100], a[100], b[100];
struct node
{
    int n, a[10], x[10];
    bool operator < (const node &rhs) const 
    {
        for (int i = 1; i < n; i++)
            if (a[i] > rhs.a[i]) return false;
            else if (a[i] < rhs.a[i]) return true;
    }
}t[100000];
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int n, k; scanf("%d%d", &n, &k);
        int tot = 0;
        if (n <= 8)
        {
            for (int i = 1; i <= n; i++) a[i] = i;
            do
            {
                ++tot;
                t[tot].n = n;
                for (int i = 1; i < n; i++) t[tot].a[i] = a[i + 1] - a[i];
                for (int i = 1; i <= n; i++) 
                {
                    t[tot].x[i] = a[i];
                }
            } while (next_permutation(a + 1, a + 1 + n));
            sort(t + 1, t + 1 + tot);
            for (int i = 1; i <= n; i++) ans[i] = t[k].x[i];
        }
        else
        {
            ans[1] = n; for (int i = 2; i <= n - 8; i++) ans[i] = i - 1;
            for (int i = 1; i <= 8; i++) a[i] = n - 9 + i;
            int tmp = ans[n - 8];
            do
            {
                ++tot;
                t[tot].n = 9;
                t[tot].a[1] = a[1] - tmp;
                for (int i = 2; i <= 8; i++) t[tot].a[i] = a[i] - a[i - 1];
                for (int i = 1; i <= 8; i++) 
                {
                    t[tot].x[i] = a[i];
                }
            } while (next_permutation(a + 1, a + 1 + 8));
            sort(t + 1, t + 1 + tot);
            for (int i = 1; i <= 8; i++) ans[n - 8 + i] = t[k].x[i];
        }
        for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n? '\n' : ' ');
    }
	return 0;
}
