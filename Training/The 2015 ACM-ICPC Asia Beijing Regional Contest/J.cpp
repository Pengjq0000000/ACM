#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int ans=0;
        while (n--)
        {
            char s[5];
            scanf("%s",s);
            if (s[0]=='S') ans++;
            else
            {
                int tmp;scanf("%d",&tmp);
                if (tmp==1) ans++;
            }
       
        }
        printf("%d\n",ans);
    }
    return 0;
}
