#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
#define uLL unsigned long long
using namespace std;
uLL a[40], b[40], S;
int n;
unordered_map<uLL, string>sta1, sta2;
set<LL>vis1, vis2;
int main()
{
	scanf("%d", &n); scanf("%llu", &S);
    for (int i = 1; i <= n; i++) scanf("%llu", &a[i]);
    int sz1 = n / 2;
    int sz2 = n - sz1;
    for (int i = 1; i <= sz2; i++) b[i] = a[i + sz1];
    int bits = (1 << sz1);
    for (int i = 0; i < bits; i++)
    {
        uLL tmp = 0; string ss = "";
        for (int j = 0; j < sz1; j++)
            if ((i >> j) & 1)
            {
                tmp += a[j + 1];
                ss += "1";
            }
            else ss += "0";
        if (!vis1.count(tmp))
        {
            //reverse(ss.begin(), ss.end());
            vis1.insert(tmp);
            sta1[tmp] = ss;
        }
    }
    bits = (1 << sz2);
    for (int i = 0; i < bits; i++)
    {
        uLL tmp = 0; string ss = "";
        for (int j = 0; j < sz2; j++)
            if ((i >> j) & 1)
            {
                tmp += b[j + 1];
                ss += "1";
            }
            else ss += "0";
        if (!vis2.count(tmp))
        {
            //reverse(ss.begin(), ss.end());
            vis2.insert(tmp);
            sta2[tmp] = ss;
        }
    }
    //for (uLL x : vis1) printf("%llu ", x); puts("");
    //for (uLL x : vis2) printf("%llu ", x); puts("");
    if (vis1.count(S))
    {
        cout << sta1[S];
        for (int i = 1; i <= sz2; i++) cout << "0";
        return 0;
    }
    if (vis2.count(S))
    {
        for (int i = 1; i <= sz1; i++) cout << "0";
        cout << sta2[S];
        return 0;
    }
    for (uLL x : vis1)
    {
        if (vis2.count(S - x))
        {
            cout << sta1[x] << sta2[S - x];
            return 0;
        }
    }
	return 0;
}
