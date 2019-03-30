#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 7368800;
LL mod;
int vis[maxn];
int prime[maxn],tot=0; //1 ~ tot
void get_prime(int maxl) // get prime <= maxl
{
    for (int i=2;i<=maxl;i++)
    {
        if (!vis[i]) prime[++tot]=i; 
        for (int j=1;j<=tot;j++)
        {
            if (i*prime[j]>maxl) break;
            vis[i*prime[j]]=1;
            if (i%prime[j]==0) break;
        }
    }
}
LL ksm(LL a, LL b)
{
	LL res = 1, base = a;
	while (b)
	{
		if (b & 1) res = MOD(res * base);
		base = MOD(base * base);
		b /= 2;
	}
	return res;
}
struct Mat
{
	LL mat[3][3];
	Mat() { MEM(mat, 0);}
	Mat friend operator * (const Mat &a, const Mat &b)
	{
		Mat c;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++)
				{
					c.mat[i][j] = MOD(c.mat[i][j] + a.mat[i][k] * b.mat[k][j]);
				}
		return c;
	}
};
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if (b==0)
	{
		x=1;y=0;
		return a;
	}
	LL g=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}
LL inverse(LL a,LL p)
{
	LL inv,k,g;
	g=exgcd(a,p,inv,k);
	inv=MOD(MOD(inv)+p);
	return inv;
}
int main()
{
	get_prime(7368799);
	LL n, m; 
	while (scanf("%lld%lld", &n, &m) != EOF)
	{
		mod = m;
		LL inv = inverse(3, m);
		LL ans;
		if (n == 1) ans = MOD(2 * inv);
		else if (n == 2) ans = MOD(3 * inv);
		else
		{
			LL x = prime[n] - 2;
			Mat res, base;
			res.mat[0][0] = res.mat[0][1] = 1;
			base.mat[0][0] = 0; base.mat[0][1] = 1;
			base.mat[1][0] = 1; base.mat[1][1] = 1;
			while (x)
			{
				if (x & 1) res = res * base;
				base = base * base;
				x /= 2; 
			}
			ans = MOD(res.mat[0][1] * inv); 
		}
		int cnt = 0; LL tmp = ans;
		while (tmp)
		{
			++cnt; tmp /= 10;
		}
		for (int i = 0; i < 9 - cnt; i++) printf("*");
		printf("%lld\n", ans);
	}
	
	return 0;
}




