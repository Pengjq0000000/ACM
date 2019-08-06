#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

void exgcd(LL a, LL b, LL &d, LL &x, LL &y)
{
    !b ? (d = a, x = 1, y = 0) : (exgcd(b, a % b, d, y, x), y -= x * (a / b)); 
}

LL a, b, S, x, y, ggcd;
bool check(__int128 x, __int128 y)
{
    return (__gcd(x, y) == 1);
}
int main()
{
    freopen("e.in", "r", stdin);
	scanf("%lld%lld%lld", &a, &b, &S);
    if (a == 0 && b == 0)
    {
        if (S == 0) puts("YES");else puts("NO");
        return 0;
    }
    else if (a == 0)
    {
        if (S % b == 0) puts("YES");else puts("NO");
        return 0;
    }
    else if (b == 0)
    {
        if (S % a == 0) puts("YES");else puts("NO");
        return 0;
    }
    if (a + b == S||a==S||b==S)
    {
        puts("YES");
        return 0;
    }
    else if (a + b > S && a != S && b != S)
    {
        puts("NO");
        return 0;
    }
    exgcd(a, b, ggcd, x, y);
    if(S%ggcd)
    {
        puts("NO");
        return 0;
    }
    __int128 aa=a,bb=b,xx=x,yy=y,lcm,tmp,xxx,yyy;
    lcm=aa*bb/ggcd;
    xx=xx*S/ggcd;yy=yy*S/ggcd;
    if(xx<=0){
        tmp=-xx/(lcm/aa);
        xx=xx%(lcm/aa)+lcm/aa;
        yy=yy-(tmp+1)*lcm/bb;
    }
    if(yy<=0){
        tmp=-yy/(lcm/bb);
        yy=yy%(lcm/bb)+lcm/bb;
        xx=xx-(tmp+1)*lcm/aa;
    }
    if(xx<=0||yy<=0){
        puts("NO");
        return 0;
    }
    if(check(xx,yy)){
        puts("YES");
        return 0;
    }
    xxx=xx;yyy=yy;
    while(xx-lcm/aa>0&&yy+lcm/bb>0){
        xx-=lcm/aa;
        yy+=lcm/bb;
        if(check(xx,yy)){
            puts("YES");
            return 0;
        }
    }
    xx=xxx;yy=yyy;
    while(xx+lcm/aa>0&&yy-lcm/bb>0){
        xx+=lcm/aa;
        yy-=lcm/bb;
        if(check(xx,yy)){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
	return 0;
}
