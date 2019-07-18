


#define mod 1000000007
// mod should be a prime


/* O(n) for all*/
int inv[maxn];
inv[1]=1;
for (int i=2;i<maxn;i++)
    inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
    

/* O(log mod) for one */

LL inv(LL i) 
{
    if (i==1) return 1;
    return (mod-mod/i)*inv(mod%i)%mod;
}

//or  //inv[i]=ksm(i,mod-2);






// or 
// gcd(a, p) == 1
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
