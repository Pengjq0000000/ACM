#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;

LL S[5];
int main()
{
    int n; 
    while (~scanf("%d", &n))
    {
        S[0] = 1; S[1] = S[2] = S[3] = S[4] = 0;
        for (int i = 1; i <= n; i++)
        {
            LL x; scanf("%lld", &x);
            for (int k = 4; k > 0; k--)
            {
                S[k] = (S[k] + S[k - 1] * x) % mod;
            }
        }
        printf("%lld\n", S[4]);
    }
    return 0;
}