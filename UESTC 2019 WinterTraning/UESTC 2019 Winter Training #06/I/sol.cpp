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
    LL h,w;scanf("%lld%lld",&h,&w);
    LL ans=1e18;
    LL s1,s2,s3;
    LL tmp=h/3;if (h%3==2) tmp++;ans=min(ans,abs(3*tmp-h)*w);

    s1=tmp*w;s2=(h-tmp)*(w/2);s3=(h-tmp)*(w-w/2);
    ans=min(ans,max(s1,max(s2,s3))-min(s1,min(s2,s3)));

    tmp=w/3;if (w%3==2) tmp++;ans=min(ans,h*abs(3*tmp-w));


    s1=tmp*h;s2=(w-tmp)*(h/2);s3=(w-tmp)*(h-h/2);
    ans=min(ans,max(s1,max(s2,s3))-min(s1,min(s2,s3)));
    printf("%lld\n",ans);
    return 0;
}

