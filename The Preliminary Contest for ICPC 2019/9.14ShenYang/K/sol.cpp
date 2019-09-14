#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)

using namespace std;
#define rep(i,a,n) for (long long i=a;i<n;i++)
#define per(i,a,n) for (long long i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((long long)(x).size())
typedef vector<long long> VI;
typedef long long ll;
typedef pair<long long,long long> PII;
const ll mod=1e9+7;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head
 
long long _,n;
namespace linear_seq
{
    const long long N=10010;
    ll res[N],base[N],_c[N],_md[N];
 
    vector<long long> Md;
    void mul(ll *a,ll *b,long long k)
    {
        rep(i,0,k+k) _c[i]=0;
        rep(i,0,k) if (a[i]) rep(j,0,k)
            _c[i+j]=(_c[i+j]+a[i]*b[j])%mod;
        for (long long i=k+k-1;i>=k;i--) if (_c[i])
            rep(j,0,SZ(Md)) _c[i-k+Md[j]]=(_c[i-k+Md[j]]-_c[i]*_md[Md[j]])%mod;
        rep(i,0,k) a[i]=_c[i];
    }
    long long solve(ll n,VI a,VI b)
    { // a 系数 b 初值 b[n+1]=a[0]*b[n]+...
//        printf("%d\n",SZ(b));
        ll ans=0,pnt=0;
        long long k=SZ(a);
        assert(SZ(a)==SZ(b));
        rep(i,0,k) _md[k-1-i]=-a[i];_md[k]=1;
        Md.clear();
        rep(i,0,k) if (_md[i]!=0) Md.push_back(i);
        rep(i,0,k) res[i]=base[i]=0;
        res[0]=1;
        while ((1ll<<pnt)<=n) pnt++;
        for (long long p=pnt;p>=0;p--)
        {
            mul(res,res,k);
            if ((n>>p)&1)
            {
                for (long long i=k-1;i>=0;i--) res[i+1]=res[i];res[0]=0;
                rep(j,0,SZ(Md)) res[Md[j]]=(res[Md[j]]-res[k]*_md[Md[j]])%mod;
            }
        }
        rep(i,0,k) ans=(ans+res[i]*b[i])%mod;
        if (ans<0) ans+=mod;
        return ans;
    }
    VI BM(VI s)
    {
        VI C(1,1),B(1,1);
        long long L=0,m=1,b=1;
        rep(n,0,SZ(s))
        {
            ll d=0;
            rep(i,0,L+1) d=(d+(ll)C[i]*s[n-i])%mod;
            if (d==0) ++m;
            else if (2*L<=n)
            {
                VI T=C;
                ll c=mod-d*powmod(b,mod-2)%mod;
                while (SZ(C)<SZ(B)+m) C.pb(0);
                rep(i,0,SZ(B)) C[i+m]=(C[i+m]+c*B[i])%mod;
                L=n+1-L; B=T; b=d; m=1;
            }
            else
            {
                ll c=mod-d*powmod(b,mod-2)%mod;
                while (SZ(C)<SZ(B)+m) C.pb(0);
                rep(i,0,SZ(B)) C[i+m]=(C[i+m]+c*B[i])%mod;
                ++m;
            }
        }
        return C;
    }
    long long gao(VI a,ll n)
    {
        VI c=BM(a);
        c.erase(c.begin());
        rep(i,0,SZ(c)) c[i]=(mod-c[i])%mod;
        return solve(n,c,VI(a.begin(),a.begin()+SZ(c)));
    }
};
///////////////////////////////////////////////////////////////////////// 




long long aa;bool bb;char ch;
long long scan()
{
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
	while(ch=getchar(),(ch>='0'&&ch<='9'))
		aa=aa*10+ch-48;
	return (bb?(-aa):(aa));
}
LL ksm(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = MOD(res * a);
        a = MOD(a * a);
        b /= 2;
    }
    return res;
}
LL inv(LL x) {return ksm(x, mod - 2);}
long long p[1000], a[100][100];
LL f[100010], sum[100010];
int main(){
    int T; int k; LL n;
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&k,&n);
		for(int i=1;i<=2*k;++i){
			scanf("%lld",&f[i]);
		}
		for(int i=k+1;i<=2*k;++i){
			a[i-k][k+1]=f[i];
			for(int j=1;j<=k;++j){
				a[i-k][j]=f[i-j];
			}
		}
		for(int i=1;i<=k;++i)
		{
            int tmp=i; LL w;
			for(int j=i;j<=k;++j)
				if((a[j][i])>0){
					tmp=j;
					break;
				}
			if(tmp!=i)
				for(int j=1;j<=k+1;++j)
				{
					w=a[tmp][j];
					a[tmp][j]=a[i][j];
					a[i][j]=w;
				}
			for(int j=i+1;j<=k;++j)
			{
				w=MOD(a[j][i]*inv(a[i][i]));
				for(int x=1;x<=k+1;++x)
					a[j][x]=MOD(a[j][x]-MOD(w*a[i][x])+mod);
			}
		}
		
		for(int i=k;i;--i)
		{
			for(int j=i+1;j<=k;++j)
				a[i][k+1]=MOD(a[i][k+1]-MOD(a[j][k+1]*a[i][j])+mod);
			a[i][k+1]=MOD(a[i][k+1]*inv(a[i][i]));
		}


        
        for (int i = 1; i <= k; i++) 
        {
            p[i] = a[i][k + 1];
            //printf("%lld ",p[i]);
        }
        //puts("");
        
        for (int i = 2 * k + 1; i <= 5000; i++)
        {
            f[i] = 0;
            for (int j = 1; j <= k; j++) 
            {
                f[i] = MOD(f[i] + MOD(p[j] * f[i - j]));
            }
        }
        VI vec;
        //for (int i = 1; i <= 10; i++) printf("%lld ", f[i]); puts("");
        for (int i = 1; i <= 5000; i++)
        {
            sum[i] = MOD(sum[i - 1] + f[i]);
            vec.pb(sum[i]);
            //printf("%lld ", sum[i]);
        }
        //puts("");
        printf("%lld\n", linear_seq::gao(vec, n - 1));
	}
}