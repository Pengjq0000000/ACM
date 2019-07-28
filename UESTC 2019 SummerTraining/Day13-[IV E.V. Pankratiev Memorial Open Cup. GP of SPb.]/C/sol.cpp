#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int len,ans,mmax,maxid,last[200],maxl[200];
char s[5010];
int ddel,del[5001],ide;
int main()
{
	freopen("falling.in", "r", stdin);
    freopen("falling.out", "w", stdout);
    scanf("%s",s+1);
    len=strlen(s+1);
    while(ddel!=len){
        ++ans;
        for(int j='a';j<='z';++j){
            last[j]=maxl[j]=0;
        }
        mmax=0,maxid=0;
        ide=0;
        for(int i=1;i<=len;++i){
            if(!del[i]){
                ++ide;
                if(last[s[i]]==0){
                    maxl[s[i]]=1;
                    if(maxl[s[i]]>mmax){
                        mmax=maxl[s[i]];
                        maxid=i;
                    }
                }
                else{
                    if(maxl[s[i]]<(ide-last[s[i]]+1)){
                        maxl[s[i]]=(ide-last[s[i]]+1);
                        if(maxl[s[i]]>mmax){
                            mmax=maxl[s[i]];
                            maxid=i;
                        }
                    }
                }
                last[s[i]]=ide;
            }
            
        }
        //cout<<mmax<<" "<<maxid<<endl;
        for(int j=maxid,k=0;k<mmax;--j){
            if(del[j])
            {
                continue;
            }
            ++k;
            del[j]=1;
            ++ddel;
        }
    }
    cout<<ans<<endl;
	return 0;
}
/*acabcaca */