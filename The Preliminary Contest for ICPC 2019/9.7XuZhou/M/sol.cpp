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
int n,m,last[300],pos[1000010];
char s[1000010],t[1000010];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	scanf("%s",t+1);
	t[m+1]='a'-1;
	int i,j=1;
	for(i=1;i<=n;++i){
		if(s[i]==t[j]){
			pos[j]=i;
			++j;
		}
	}
	int ans=-1;
	i=n;
	for(j=m+1;j>=1;--j){
		if(j>1&&pos[j-1]==0)
			continue;
		while(i>pos[j-1]){
			last[s[i]]=i;
			--i;
		}
		for(int k=t[j]+1;k<='z';++k){
			if(last[k]){
				//cout<<j<<" "<<last[k]<<endl;
				ans=max(j-1+n-last[k]+1,ans);
			}
		}
	}
	printf("%d\n",ans);
}

