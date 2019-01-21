#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;

string table[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

int main()
{
    int year=1867,now=6;
    int n;scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        year++;
        int day=365;
        if ((year%4==0 && year%100!=0) || year%400==0) day++;
        now=(now+day)%7;
    }
    cout<<table[now];
    return 0;
}
