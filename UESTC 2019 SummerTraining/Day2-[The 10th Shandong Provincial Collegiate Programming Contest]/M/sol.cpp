#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int main()
{
    int T,n,k;
	scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=k;++i)
        {
            if(n<=1)
                break;
            if(n&1)
                n=n/2+1;
            else
                n>>=1;
        }
        cout<<n<<endl;
    }
	return 0;
}
