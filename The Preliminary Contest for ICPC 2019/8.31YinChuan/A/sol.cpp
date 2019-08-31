#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
stack<unsigned long long>stk, mx;
unsigned int nowmx;
int n, p, q, m;
unsigned int SA, SB, SC;
unsigned long long ans, cnt;
unsigned int rng61(){
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA; SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
void PUSH(unsigned long long x)
{
    ++cnt;
    stk.push(x);
    mx.push(max(mx.top(), x));
    ans ^= (mx.top() * cnt);
}
void POP()
{
    ++cnt;
    if (stk.empty()) return;
    stk.pop();
    mx.pop();
    ans ^= (mx.top() * cnt);
}
void gen(){
    scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
    for (int i = 1; i <= n; i++) {
        if (rng61() % (p + q) < p)
            PUSH(rng61() % m + 1);
        else POP();
    }
}

int main()
{
    int T, cas = 0; scanf("%d", &T);
    while (T--)
    {
	    while (stk.size()) stk.pop();
        while (mx.size()) mx.pop();
        mx.push(0); nowmx = 0; ans = 0; cnt = 0;
        gen();
        printf("Case #%d: %llu\n", ++cas, ans);
    }

	return 0;
}
