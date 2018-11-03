


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



