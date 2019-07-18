#include<bits/stdc++.h>
using namespace std;
long long aa;bool bb;char ch;
long long scan()
{
    while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
    ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
    while(ch=getchar(),(ch>='0'&&ch<='9'))
        aa=aa*10+ch-48;
    return (bb?(-aa):(aa));
}
struct P{
    long long x,y;
} p[3];
P operator -(P u,P v){
    P ret;
    ret.x=u.x-v.x;
    ret.y=u.y-v.y;
    return ret;
}
long long SS;
long long Abs(long long u){return u>0?u:(-u);}
long long cross(P u,P v){return u.x*v.y-u.y*v.x;}
int main()
{
    while(scanf("%lld%lld%lld%lld%lld%lld",&p[1].x,&p[1].y,&p[2].x,&p[2].y,&p[0].x,&p[0].y)!=EOF)
    {
		SS=Abs(cross(p[2]-p[0],p[1]-p[0]));
		SS*=11;
		cout<<SS<<endl;
	}
}
