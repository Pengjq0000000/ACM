#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
char s[107];
int main()
{
    int n; scanf("%d", &n);
    scanf(" %s", s);
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0') cnt0++; else cnt1++;
    }
    if (cnt0 != cnt1)
    {
        puts("1");
        printf("%s\n", s);
        return 0;
    }
    puts("2");
    printf("%c ", s[0]);
    for (int i = 1; i < n; i++) printf("%c", s[i]);
	return 0;
}
