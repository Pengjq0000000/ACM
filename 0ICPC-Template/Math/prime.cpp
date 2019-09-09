/// O(n)
const int maxn = 1e6+7;
int vis[maxn];
int prime[maxn], mu[maxn], minprim[maxn], tot = 0; //1 ~ tot
void get_prime(int maxl) // get prime <= maxl
{
    minprim[1] = 1;
    for (int i = 2; i <= maxl; i++)
    {
        if (!vis[i])
        {
            prime[++tot] = i; minprim[i] = i;
        }
        for (int j = 1; j <= tot; j++)
        {
            if (i * prime[j] > maxl) break;
            vis[i * prime[j]] = 1;
            minprim[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) 
            {
            	break;
            }
        }
    }
    //vis[i] == 0 -> i is a prime
}
