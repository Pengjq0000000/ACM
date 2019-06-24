/// O(n)
const int maxn = 1e6+7;
int vis[maxn];
int prime[maxn], tot = 0; //1 ~ tot
void get_prime(int maxl) // get prime <= maxl
{
    for (int i = 2; i <= maxl; i++)
    {
        if (!vis[i]) prime[++tot] = i; 
        for (int j = 1; j <= tot; j++)
        {
            if (i * prime[j] > maxl) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    //vis[i] == 0 -> i is a prime
}
