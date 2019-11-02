#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 1007;
char s[maxn];
int A[maxn*10],B[maxn*10];
int main()
{
    scanf("%s",s);
    int L=strlen(s);
    int tot=0;
    for (int i=0;i<L-1;i++)
    {
        int mi=1e9,pos;
        for (int j=i+1;j<L;j++)
        {
            if (mi>s[j])
            {
                mi=s[j];pos=j;
            }
        }
        if (s[i]>mi)
        {
            swap(s[i],s[pos]);
            A[++tot]=pos+1;B[tot]=i+1;
        }
    }
    for (int i=tot;i>=1;i--)
        printf("%d %d\n",A[i],B[i]);
    return 0;
}
