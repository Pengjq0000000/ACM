#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

char s[10005];
int cnt;
char b[100005];
int num[100005];
int main()
{
	scanf(" %s",s);
    int len=strlen(s);
	for(int i=len-1;i>=0;i--)
    {
        if(s[i]!=s[i+1])
        {
            cnt++;
            b[cnt]=s[i];
            num[cnt]=1;
        }
        else num[cnt]++;
    }
    for(int i=1;i<=cnt;i++)
    {
        if(b[i]=='b')
        {
            num[i]=(num[i]-1)%2+1;
            num[i]=2-num[i];
            for(int j=1;j<=num[i];j++)
                printf("%c",b[i]);
        }
        else
        {
            num[i]=(num[i]-1)%6+1;
            num[i]=6-num[i];
            for(int j=1;j<=num[i];j++)
                printf("%c",b[i]);
        }
    }
    return 0;
}
