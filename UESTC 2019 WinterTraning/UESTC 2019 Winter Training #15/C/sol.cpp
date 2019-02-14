#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1007;
int mp[maxn][maxn];
int r,s,p;
priority_queue<int>q;
int main()
{
    scanf("%d%d%d",&r,&s,&p);
    for (int i=1;i<=p;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        int tim=r-y+1;
        if (x<=s) tim+=s-x+1;else tim+=x-s;
        q.push(-tim);
    }
    int ans=0;
    while (!q.empty())
    {
        ans++;
        int now=-q.top();
        if (ans>=now) q.pop();
    }
    printf("%d\n",ans);
    return 0;
}
/*
5 2 7
1 1
1 2
1 3
2 3
2 4
4 4
5 2
*/

