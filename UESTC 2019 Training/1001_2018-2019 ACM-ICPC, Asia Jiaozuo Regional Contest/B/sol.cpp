#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll A,B,atka,atkb;
ll cal(ll x)
{
    return x*(x+1)/2;
}
ll find(ll a)
{
    ll l=0,r=a;
    ll res;
    while(l<=r)
    {
        ll m=(l+r)/2;
        if(cal(m)>=a) r=m-1,res=m;
        else l=m+1;
    }
    return res;
}
ll find2(ll a,ll y)
{
    ll l=y,r=1e9;
    ll res;
    while(l<=r)
    {
        ll m=(l+r)/2;
        if(cal(m)-cal(y)>=a) r=m-1,res=m;
        else l=m+1;
    }
    return res;
}
string s1;
string s2,lastans,tmpans;
bool dfs(ll now,ll l,ll r,ll lim){
    if(now>lim) return 0;
    if(r<0) return 0;
    if(r==0) return 1;
    if(l<=0) {
        tmpans=s2;
        if(lastans>tmpans)
            lastans=tmpans;
    } 
    for(ll i=now;i<=lim;i++)
    {
        if(r<i) break;
        s2[i-1]='A';
        if(dfs(i+1,l-i,r-i,lim)) return 1;
        s2[i-1]='B';
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld",&A,&B,&atka,&atkb);
        ll ans1,ans2;
        ll xa=find(A);
        ll ya=cal(xa)-A;
        ll xb=find2(B-ya,xa)-xa;
        ll yb=cal(xb+xa)-cal(xa)-(B-ya);
        ans1=atka*xa+atkb*(xa+xb);
        s1=""; s2="";
        for(int i=1;i<=xa;i++) s1+='A';
        for(int i=xa+1;i<=xa+xb;i++) s1+='B';
        if(ya>yb) s1[ya-1]='B';

        ll xb2=find(B);
        ll yb2=cal(xb2)-B;
        ll xa2=find2(A-yb2,xb2)-xb2;
        ll ya2=cal(xa2+xb2)-cal(xb2)-(A-yb2);
        ans2=atkb*xb2+atka*(xb2+xa2);
        for(int i=1;i<=xb2;i++) s2+='B';
        for(int i=xb2+1;i<=xb2+xa2;i++) s2+='A';
        lastans="";
        lastans+='Z';
        dfs(1,yb2-ya2,yb2,xb2);
        if(lastans<s2)
            s2=lastans;
        if(ans1<ans2) cout<<ans1<<' '<<s1<<endl;
        else if(ans1>ans2) cout<<ans2<<' '<<s2<<endl;
        else
        {
            if(s1<s2) cout<<ans1<<' '<<s1<<endl;
            else cout<<ans2<<' '<<s2<<endl;
        }
    }
}
/*
6
15 5 5 25
5 15 5 25
5 15 25 5
234523 56747 232 6546
2314 234 345 2978
231 23 34 297
*/