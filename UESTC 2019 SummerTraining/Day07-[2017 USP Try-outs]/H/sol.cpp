#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int x,y,xx,yy;
char ch;
int ans[100],cnt=0;
int dis(int a,int b,int c,int d){
    return abs(a-c)+abs(b-d);
}
int main()
{
	scanf("%d%d",&x,&y);
    cin>>ch;
	scanf("%d%d",&xx,&yy);
    while(x!=xx||y!=yy){
        if(ch=='O'){
            if(dis(x-1,y,xx,yy)>dis(x,y,xx,yy))
            {
                ans[++cnt]=-1;
                ch='N';
            }
            else
            {
                ans[++cnt]=x-xx;
                x=xx;
            }
            
        }
        else if(ch=='N'){
            if(dis(x,y+1,xx,yy)>dis(x,y,xx,yy))
            {
                ans[++cnt]=-1;
                ch='E';
            }
            else
            {
                ans[++cnt]=yy-y;
                y=yy;
            }
        }
        else if(ch=='E'){
            if(dis(x+1,y,xx,yy)>dis(x,y,xx,yy))
            {
                ans[++cnt]=-1;
                ch='S';
            }
            else
            {
                ans[++cnt]=xx-x;
                x=xx;
            }
        }
        else if(ch=='S'){
            if(dis(x,y-1,xx,yy)>dis(x,y,xx,yy))
            {
                ans[++cnt]=-1;
                ch='O';
            }
            else
            {
                ans[++cnt]=y-yy;
                y=yy;
            }
        }
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;++i){
        if(ans[i]==-1)
            puts("D");
        else
        {
            printf("A %d\n",ans[i]);
        }
        
    }
	return 0;
}
