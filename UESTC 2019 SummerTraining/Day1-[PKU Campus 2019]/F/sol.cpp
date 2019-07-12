#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int add[6],have[6],need[6],fflag[6],tab[1000],ans[20],anscnt,anstp,tmp[20],tmpcnt;
int id[20],typ[20],crd[20],K[20],x,a,b;
int mp[20][200];
int flag,flag12,Bits;
void init(){
    memset(add,0,sizeof add);
    memset(fflag,0,sizeof fflag);
    memset(tab,0,sizeof tab);
    flag=0;
    flag12=0;
}
int n,t;
int main()
{
	scanf("%d",&t);
    while(t--){
        anstp=0;
        memset(mp,0,sizeof mp);
        scanf("%d%d%d%d%d",&have[1],&have[2],&have[3],&have[4],&have[5]);
        scanf("%d%d%d%d%d",&need[1],&need[2],&need[3],&need[4],&need[5]);
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d%d%d%d",&id[i],&typ[i],&crd[i],&K[i]);
            for(int j=1;j<=K[i];++j){
                scanf("%d%d%d",&x,&a,&b);
                for(int k=a;k<=b;++k)
                {
                    mp[i][x+k*7-7]=1;
                }
            }
        }
        int Bits=(1<<n)-1;
        //cout<<Bits<<endl;
        for(int tt=0;tt<=Bits;++tt){
            
            init();
            for(int i=0,j=1;i<n;++i,j<<=1){
                if(!(tt&j)) continue;
                if(typ[i]>=3&&fflag[typ[i]]){
                    break;
                }
                for(int k=0;k<=100;++k)
                {
                    if(tab[k]&&mp[i][k]){
                        flag=1;
                        break;
                    }
                    if(mp[i][k])
                        tab[k]=1;
                    if(k>=77)
                        flag12=1;
                }
                if(flag)
                    break;
                if(typ[i]>=3)
                    fflag[typ[i]]=1;
                add[typ[i]]+=crd[i];
                add[0]+=crd[i];
                if(add[0]>25){
                    flag=1;
                    break;
                }
            }
            for(int i=1;i<=5;++i){
                if(have[i]+add[i]<need[i]){
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                continue;
            if(flag12==0){
                anstp=1;
            }
            else if(anstp!=1){
                tmpcnt=0;
                for(int i=0,j=1;i<n;++i,j<<=1){
                    if(tt&j){tmp[++tmpcnt]=id[i];}
                }
                if(anstp==0||tmpcnt<anscnt)
                {
                    for(int i=1;i<=tmpcnt;++i)
                        ans[i]=tmp[i];
                    anscnt=tmpcnt;
                    sort(ans+1,ans+anscnt+1);
                }
                anstp=2;
            }
        }
        if(anstp==0)
            puts("unable to graduate");
        else if(anstp==1)
            puts("able to graduate");
        else{
            puts("able to graduate");
            for(int i=1;i<=anscnt;++i)
                cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
	return 0;
}
