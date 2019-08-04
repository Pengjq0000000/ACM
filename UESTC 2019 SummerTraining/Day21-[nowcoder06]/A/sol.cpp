#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m;
int num[200];
char s[2005];
char h[200];
int main()
{
    int T;
    scanf("%d",&T);
    for(int k=1;k<=T;k++)
    {
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0;i<26;i++)
            scanf(" %c",&h['a'+i]);
        for(int i=0;i<len;i++)
            s[i]=h[s[i]];
        for(int i=0;i<len;i++)
            num[s[i]]++;
        printf("Case #%d: ",k);
        if(4*num['h']>=len) printf("Harmful\n");
        else if(10*num['h']<=len) printf("Recyclable\n");
        else if(num['d']>=2*num['w']) printf("Dry\n");
        else printf("Wet\n");
        for(int i=0;i<len;i++)
            num[s[i]]--;
         
    }
    return 0;
}
