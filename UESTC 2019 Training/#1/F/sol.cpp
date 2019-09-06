#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int m,n;
int num[20003];
int maxv;
int res;
int k;
bool sign;
void ini()
{
    int up=min(2*(n-1),20000);
    for(int i=0;i<=up;i++)
        num[i]=0;
    maxv=0;
    res=0;
    k=n;
    sign=1;
}
int main()
{
	while(scanf("%d",&m)!=EOF)
    {
        while(m--)
        {
            scanf("%d",&n);
            ini();
            for(int i=1;i<=n;i++)
            {
                int t;
                scanf("%d",&t);
                num[t]++;
                maxv=max(maxv,t);
            }
            for(int i=maxv;i>=1;i--)
            {
                if(res>=num[i])
                {
                    num[i-1]+=num[i];
                    num[i]=0;
                    res-=num[i];
                    continue;
                }
                else if(res)
                {
                    num[i-1]+=res;
                    num[i]-=res;
                    res=0;
                }
                int up=2*(k-1);
                if(i>up)
                {
                    sign=0;
                    break;
                }
                else
                {
                    res+=num[i]*(up-i);
                    k-=num[i];
                    num[i]=0;
                }
            }
            if(k!=0||res!=0||sign==0) printf("F\n");
            else printf("T"); 
        }
    }
	return 0;
}
