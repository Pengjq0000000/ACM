#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
map<string,int>mp;
vector<int>v[200];
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        mp.clear();
        int tot=0,ans=0;
        int n;scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            string s;int val;cin>>s>>val;
            if (mp[s]==0) mp[s]=++tot;
            v[mp[s]].pb(val);
        }
        for (int i=1;i<=tot;i++)
        {
            sort(v[i].begin(),v[i].end());
            int sz=v[i].size();
            if (sz>0) ans+=v[i][sz-1];
            if (sz>1) ans+=v[i][sz-2]; 
            v[i].clear();
        }
        printf("%d\n",ans);
    }
    return 0;
}
