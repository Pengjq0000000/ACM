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
int n,ans,now;
char s[250010],pre;
int main(){
	scanf("%d",&n);
	ans=1;
	scanf("%s",s+1);
	now=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='V'){
			if(now>ans)
				ans=now;
			now=0;
		}
		else{
			if(now==0){
				pre=s[i];
				now=1;
				continue;
			}
			if(s[i]==s[i-1]){
				if(now>ans)
					ans=now;
				pre=s[i];
				now=1;
				continue;
			}
			pre=s[i];
			now++;
			if(now>ans)
				ans=now;
		}
	}
	cout<<ans<<endl;
}
