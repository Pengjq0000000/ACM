#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
char s1[4010],s2[4010];
deque<int> q;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        getchar();
        for(int i=1;i<=n;++i)
            s1[i]=getchar();
        
        getchar();
        for(int i=1;i<=m;++i)
            s2[i]=getchar();
        int ans=0;
        
        for(int i=1;i<=n;++i)//s1 from i to n; s2 from 1 to m;
        {
            q.clear();
            int use=0,x,y,lastpos=0;
            for(x=i,y=1;x<=n&&y<=m;++x,++y){
                if(s1[x]==s2[y]){
                    ans=max(ans,y-lastpos);
                }
                else{
                    if(k==0){
                        lastpos=y;
                        continue;
                    }
                    else{
                        if(use<k){
                            ++use;
                            ans=max(ans,y-lastpos);
                            q.push_back(y);
                        }
                        else{
                            lastpos=q.front();
                            q.pop_front();
                            ans=max(ans,y-lastpos);
                            q.push_back(y);
                        }
                    }
                }
            }

        }
        
        for(int j=1;j<=m;++j)//s1 from 1 to n; s2 from j to m;
        {
            q.clear();
            int use=0,x,y,lastpos=0;
            for(x=1,y=j;x<=n&&y<=m;++x,++y){
                if(s1[x]==s2[y]){
                    ans=max(ans,x-lastpos);
                }
                else{
                    if(k==0){
                        lastpos=x;
                        continue;
                    }
                    else{
                        if(use<k){
                            ++use;
                            ans=max(ans,x-lastpos);
                            q.push_back(x);
                        }
                        else{
                            lastpos=q.front();
                            q.pop_front();
                            ans=max(ans,x-lastpos);
                            q.push_back(x);
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}
/*
100
5 6 0
abcde
bcddff
*/