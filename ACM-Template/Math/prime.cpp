/// O(n)
const int maxn = 1e6+7;
int vis[maxn];
int prime[maxn], mu[maxn], tot = 0; //1 ~ tot
void get_prime(int maxl) // get prime <= maxl
{
	mu[1] = 1;
    for (int i = 2; i <= maxl; i++)
    {
        if (!vis[i]) prime[++tot] = i, mu[i] = -1; 
        for (int j = 1; j <= tot; j++)
        {
            if (i * prime[j] > maxl) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) 
            {
            	mu[i * prime[j]] = 0;
            	break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
    //vis[i] == 0 -> i is a prime
}
