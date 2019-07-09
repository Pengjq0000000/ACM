#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int T,n,a[maxn];
int ans[maxn],cnt[maxn];
int qcnt=0;
struct Que{
    int id,x,y;
    bool operator < (const Que &rhs) const
    {
         
        if(x / 336 == rhs.x / 336)
        {
            if((x/336)&1)
                return y>rhs.y;
            else
                return y<rhs.y;
        }
        
        return x / 336 < rhs.x / 336;
    }
} q[maxn];
int last[maxn];
int vis[maxn];
int qANS[maxn], times[maxn];
void modui(){
    for (int i = 0; i <= n; i++) times[i] = 0;
    sort(q+1,q+qcnt+1);
    int l = 1, r = 1, now = 1;
    times[a[l]]++;
    for (int i = 1; i <= qcnt; i++) qANS[i] = 0;
    for (int i = 1; i <= qcnt; i++)
    {
        while (q[i].y > r) 
        {
            r++; times[a[r]]++;
            if (times[a[r]] == 1) now++; 
        }
        while (q[i].x > l)
        {
            times[a[l]]--;
            if (times[a[l]] == 0) now--;
            l++;
        }
        while (q[i].x < l)
        {
            l--; times[a[l]]++;
            if (times[a[l]] == 1) now++; 
        }
        while (q[i].y < r)
        {
            times[a[r]]--;
            if (times[a[r]] == 0) now--;
            r--;
        }
        qANS[q[i].id] = now;
    }
    
    for (int i = 1; i <= qcnt; i++) cnt[qANS[i]]++;
}
int main()
{
	scanf("%d",&T);
    while(T--){
        qcnt=0;
        scanf("%d",&n);
        for(int i=0;i<=n;++i){
            vis[i]=0;
            last[i]=0;
            ans[i]=0;
        }
        cnt[0]=0;
        for(int i=1;i<=n;++i){
            cnt[i]=0;
            scanf("%d",&a[i]);
            if(last[a[i]]){
                q[++qcnt].x=last[a[i]];
                q[qcnt].y=i;
                q[qcnt].id=qcnt;
            }
            last[a[i]]=i;
            if(!vis[a[i]]){++ans[n];vis[a[i]]=1;}
        }
        modui();
        for(int i=n-1;i>=1;--i)
        {
            ans[i]=ans[i+1]+cnt[i+1];
        }
        for(int i=1;i<=n;++i)
        {
            printf("%d%c",ans[i], i == n ? '\n':' ');
        }
    }
	return 0;
}
