#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
char s[1005];
vector<int>pos;
int op(char c){if (c=='+'||c=='*') return 1;else return 0;}
int num(char c){return ('0'<=c && c<='9');}
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        int L=strlen(s);
        for (int i=0;i<L;i++)
        {
            if (i>1 && op(s[i-2]) && s[i-1]=='0' && s[i]=='?') s[i]='+';
            if (i==1 && s[i-1]=='0' && s[i]=='?') s[i]='+';
        }
        for (int i=0;i<L;i++) if (s[i]=='?') s[i]='1';
        int flg=0;
        if (op(s[0]) || op(s[L-1])) flg=1;
        else if (L==1 && s[0]=='0') flg=0;
        else 
        {
            for (int i=0;i<L-1;i++)
            {
                if (op(s[i]) && op(s[i+1])) 
                {
                    flg=1;break;
                }
            }
            if (s[0]=='0' && (num(s[1]))) flg=1;
            for (int i=0;i<L-2;i++)
            {
                if (op(s[i]) && s[i+1]=='0' && (num(s[i+2])))
                {
                    flg=1;break;
                }
            }
            
        }
        if (flg) puts("IMPOSSIBLE");
        else puts(s);
    }
    return 0;
}
