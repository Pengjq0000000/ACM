#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int _K=50268147,_B=6082187,_P=100000007;
const int maxn = 1000001;
int _X;
inline int get_rand(int _l,int _r)
{
  _X=((long long)_K*_X+_B)%_P;
  return _X%(_r-_l+1)+_l;
}
int n,m,k,seed;
int x[1000001],y[1000001];
void Init()
{
  scanf("%d%d%d%d",&n,&m,&k,&seed);
  _X=seed;
  for (int i=1;i<=k;++i)
    x[i]=get_rand(1,n),
    y[i]=get_rand(1,m);
} 

int visx[maxn],visy[maxn];
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        Init();
        MEM(visx,0);MEM(visy,0);
        for (int i=1;i<=k;i++) 
        {
            visx[x[i]]=visy[y[i]]=1;
            //printf("%d %d\n",x[i],y[i]);
        }
        int cntx=0,cnty=0;
        for (int i=1;i<=n;i++) if (!visx[i]) cntx++;
        for (int i=1;i<=m;i++) if (!visy[i]) cnty++;
        printf("%d %d\n",cntx,cnty); 
    }   
    return 0;
}

