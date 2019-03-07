#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5 + 7;
priority_queue<int>q;
map<int, int> has;
int a[maxn];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), q.push(a[i]), has[a[i]]++;
    int ans = 0;
    while (1)
    {
        int now = q.top();
        while (has[now] && now > 0) now /= 2;
        if (now == 0) break;
        has[q.top()]--; q.pop();
        has[now]++; q.push(now);
    }
    printf("%d\n", q.top());
    return 0;
}

