#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e7 + 7;
int lowbit(int x) {return x & -x;}
int a[100], b[100];
int tota, totb, S_tota, S_totb;
int sa[maxn], sb[maxn];
int A[maxn], B[maxn];
int cnta[maxn];
int sumb[maxn];
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        S_tota = n / 2;
        if (S_tota > 1) S_tota--;
        S_totb = n - S_tota;
        for (int i = 0; i < S_tota; i++) scanf("%d", &a[i]);
        for (int i = 0; i < S_totb; i++) scanf("%d", &b[i]);
        tota = (1 << S_tota);
        for (int sta = 1; sta < tota; sta++)
        {
            int tmp = lowbit(sta);
            sa[sta] = sa[sta ^ tmp] + a[__builtin_ctz(tmp)];
        }
        totb = (1 << S_totb);
        for (int sta = 1; sta < totb; sta++)
        {
            int tmp = lowbit(sta);
            sb[sta] = sb[sta ^ tmp] + b[__builtin_ctz(tmp)];
        }
        //for (int i = 0; i < tota; i++) printf("%d ", sa[i]); puts("");
        //for (int i = 0; i < totb; i++) printf("%d ", sb[i]); puts("");
        LL ans = 0;
        int base = 1;
        for (int k = 1; k <= 7; k++)
        {
            base *= 10;
            for (int i = 0; i < base; i++) cnta[i] = sumb[i] = 0;
            for (int i = 0; i < tota; i++) cnta[sa[i] % base]++;
            for (int i = 0; i < totb; i++) sumb[sb[i] % base]++;
            for (int i = 1; i < base; i++)
            {
                sumb[i] += sumb[i - 1];
            }
            int low = 4 * base / 10, up = 5 * base / 10;
            int L, R, posL, posR;
            for (int i = 0; i < base; i++)
            {
                int x = i;
                if (cnta[x] == 0) continue;
                if (low <= x && x < up)
                {
                    L = 0; R = up - x - 1;
                    ans += (LL)cnta[x] * sumb[R];
                    L = low - x + base; R = base - 1;
                    if (L > 0) L--;
                    ans += (LL)cnta[x] * (sumb[R] - sumb[L]);
                }
                else
                {
                    L = low - x; if (L < 0) L += base;
                    R = up - x; R--; if (R < 0) R += base;
                    if (L > 0) L--;
                    ans += (LL)cnta[x] * (sumb[R] - sumb[L]);
                }
            }
        }
        for (int k = 8; k <= 9; k++)
        {
            base *= 10;
            for (int i = 0; i < tota; i++) A[i] = sa[i] % base;
            for (int i = 0; i < totb; i++) B[i] = sb[i] % base;
            sort(A, A + tota);
            sort(B, B + totb);
            for (int i = 0; i < totb; i++) {B[i + totb] = B[i]; B[i] -= base;}
            totb *= 2;
            //for (int i = 0; i < tota; i++) printf("%d ", A[i]); puts("");
            //for (int i = 0; i < totb; i++) printf("%d ", B[i]); puts("");
            int low = 4 * (base / 10), up = 5 * (base / 10);
            int L, R;
            int posL = totb, posR = totb;
            for (int i = 0; i < tota; i++)
            {
                int x = A[i];
                L = low - x; R = up - x;
                while (posL && B[posL - 1] >= L) posL--;
                while (posR && B[posR - 1] >= R) posR--;
                if (posL < posR && posL != totb) ans += posR - posL; 
                //printf("x = %d, L=%lld R=%lld posL=%d posR=%d\n", x, L, R, posL, posR);
            }
            totb /= 2;
        }
        printf("%lld\n", ans);
    }
	return 0;
}
