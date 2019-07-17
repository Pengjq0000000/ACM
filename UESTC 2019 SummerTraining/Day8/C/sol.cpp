#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int,int>
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
pii par;
multiset<pair<pii,double> > cnt;
map<pii,int> mp;
const double eps=1e-8;
double Abs(double u){return u>0?u:(-u);}
struct P{
    int x,y;
    P(){}
    P(int x,int y):x(x),y(y){}
} u,v;
double operator *(P u,P v){
    return (double)u.x*v.y-(double)u.y*v.x;
}
int T,n;

int main()
{
	scanf("%d",&T);
    
    while(T--){
        cnt.clear();
        mp.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d%d%d%d",&u.x,&u.y,&v.x,&v.y);
            if(u.x>v.x){
                P w=u;u=v;v=w;
            }
            if(u.x==v.x){
                mp[make_pair(0,0)]++;
                cnt.insert(make_pair(make_pair(0,0),u.x));
                continue;
            }
            int yy=v.y-u.y;
            int xx=v.x-u.x;
            int gg=__gcd(xx,yy);
            yy/=gg;
            xx/=gg;
            pii par=make_pair(xx,yy);
            mp[par]++;
            cnt.insert(make_pair(make_pair(xx,yy),u*v/((double)u.x-v.x)));
            //cout<<"jieju"<<u*v/(u.x-v.x)<<endl;
        }
        bool flag=0;
        double pre;
        par=make_pair(-1,-1);
        pii tmp;
        long long ans=0;
        long long now=0;
        for(auto it=cnt.begin();it!=cnt.end();++it){
            tmp=it->first;
            ans+=n-mp[tmp];
            if(par!=tmp){
                ans+=(now)*(now-1);
                par=tmp;
                flag=0;
                now=0;
            }
            if(flag==1&&Abs(it->second-pre)<eps){
                //cout<<((it->first).first)<<" "<<((it->first).second)<<endl;
                //cout<<(it->second)<<" "<<pre<<endl;
                ++now;
            }
            else if(flag==0){
                flag=1;
                now=1;
                pre=it->second;
            }
            else{
                ans+=(now)*(now-1);
                //cout<<"nowa"<<now<<endl;
                now=1;
                pre=it->second;
            }
        }
        ans+=(now)*(now-1);
        //cout<<"nowb"<<now<<endl;
        cout<<ans/2<<endl;
    }
	return 0;
}
