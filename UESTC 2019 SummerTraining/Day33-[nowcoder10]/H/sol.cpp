#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int d[10], cnt[10], id[10];
vector<int>E[10];
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        for (int i = 1; i <= 6; i++) cnt[i] = d[i] = 0, E[i].clear();
        for (int i = 1, u, v; i < 6; i++)
        {
            scanf("%d%d", &u, &v);
            d[u]++; d[v]++;
            E[u].pb(v);
            E[v].pb(u);
        }
        for (int i = 1; i <= 6; i++) 
        {
            cnt[d[i]]++;
            id[d[i]] = i;
        }
        if (cnt[1] == 2 && cnt[2] == 4) puts("n-hexane");
        else if (cnt[1] == 4 && cnt[3] == 2) puts("2,3-dimethylbutane");
        else if (cnt[1] == 4 && cnt[2] == 1 && cnt[4] == 1) puts("2,2-dimethylbutane");
        else
        {
            int x = id[3];
            int tmp = 0;
            for (int y : E[x]) if (d[y] == 1) tmp++;
            if (tmp == 2) puts("2-methylpentane");
            else puts("3-methylpentane");
        }
    }
	return 0;
}
