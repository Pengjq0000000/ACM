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
const int maxn=200010;
struct P{
	int id,lf,rg,val; 
	bool operator <(const P &rhs) const
	{
		return val < rhs.val;
	}
} a[maxn],b[maxn],now,tmp;
int vis[maxn];
int n,k,ans=0;
priority_queue<P> Q;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i].val);
		a[i].id=i;
		a[i].lf=(i-1+n)%n;
		a[i].rg=(i+1)%n;
	}
	for(int i=0;i<n;++i)
	{
		b[i].val=a[i].val+a[(i+1)%n].val;
		b[i].lf=i;
		b[i].rg=(i+1)%n;
		Q.push(b[i]);
	}
	for(int i=1;i<=n-k;){
		now=Q.top();
		Q.pop();
		if(vis[now.lf]||vis[now.rg]){
			continue;
		}
		if(a[now.lf].val<a[now.rg].val){
			++i;
			vis[now.rg]=1;
			a[now.lf].rg=a[now.rg].rg;
			a[a[now.rg].rg].lf=now.lf;
			tmp.val=a[now.lf].val+a[a[now.rg].rg].val;
			tmp.lf=now.lf;
			tmp.rg=a[now.rg].rg;
			Q.push(tmp);
		}
		else
		{
			++i;
			vis[now.lf]=1;
			a[now.rg].lf=a[now.lf].lf;
			a[a[now.lf].lf].rg=now.rg;
			tmp.val=a[now.rg].val+a[a[now.lf].lf].val;
			tmp.rg=now.rg;
			tmp.lf=a[now.lf].lf;
			Q.push(tmp);
		}
	}
	while(1){
		now=Q.top();
		Q.pop();
		if(vis[now.lf]||vis[now.rg]){
			continue;
		}
		printf("%d\n",now.val);
		return 0;
	}
}