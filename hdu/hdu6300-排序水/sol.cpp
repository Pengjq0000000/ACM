#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
struct node
{
    int id,val;
    bool operator < (const node&rhs) const
    {
        return (val<rhs.val);
    }
}p[3005];
int main()
{
    int tmp;
    int T;scanf("%d",&T);
    while (T--)
    {
        int n;scanf("%d",&n);
        for (int i=0;i<3*n;i++) scanf("%d%d",&p[i].val,&tmp),p[i].id=i+1;
        sort(p,p+3*n);
        for (int i=0;i<n;i++)
        {
            printf("%d %d %d\n",p[3*i].id,p[3*i+1].id,p[3*i+2].id);
        }
    }
    return 0;
}
