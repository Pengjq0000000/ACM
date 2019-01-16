#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 1e5+7;
LL L[maxn];
char s[maxn];
int main()
{
    int n;scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld",&L[i]);
    scanf("%s",s+1);
    LL stamina=0,time=0,doubleGrass=0;
    int Wflag=0;
    for (int i=1;i<=n;i++)
    {
        if (s[i]=='L')
        {
            stamina-=L[i];
            time+=L[i];
            if (stamina<0)
            {
                time-=stamina*(Wflag?3:5);
                stamina=0;
            }
        }
        else if (s[i]=='W')
        {
            Wflag=1;
            stamina+=L[i];
            time+=3*L[i];
        }
        else if (s[i]=='G')
        {
            stamina+=L[i];
            time+=5*L[i];
            doubleGrass+=2*L[i];
        }
        doubleGrass=min(stamina,doubleGrass);
    }
    
    if (stamina)
    {
        time-=(5-1)*doubleGrass/2;
        time-=(3-1)*(stamina-doubleGrass)/2;   
    }
    printf("%lld\n",time);
    return 0;
}
