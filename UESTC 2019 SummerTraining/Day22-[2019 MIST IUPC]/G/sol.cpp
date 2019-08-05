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
int T,a,flag,n;

int main(){
	scanf("%d",&T);
	for(int cas=1;cas<=T;++cas){
		scanf("%d",&n);
		flag=1;
		printf("Case %d: ",cas);
		for(int i=1;i<=n;++i){
			scanf("%d",&a);
			a=((a&1)^1);
			if(a==0&&flag)
				continue;
			else
				flag=0;
			printf("%d",a);
		}
		puts("");
	} 
}
