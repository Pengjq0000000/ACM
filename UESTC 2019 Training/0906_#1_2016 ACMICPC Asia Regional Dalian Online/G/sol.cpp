#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
LL mink[maxn];
int main()
{
    int x = 1, cnt = 0, pos;
    mink[1] = 0;
    for (int i = 2; i < maxn; i++)
    {
        mink[i] = mink[i - 1] + x;
        cnt++; if (cnt == 2) {cnt = 0; x++;}
        pos = i;
        if (mink[i] > 2147483648) break;
    }  
    //printf("%d\n", pos);
	LL n, k; 
    while (~scanf("%lld%lld", &n, &k))
    {
        if (n > pos) {puts("F"); continue;}
        if (mink[n] <= k) puts("T");
        else puts("F"); 
    }
	return 0;
}
