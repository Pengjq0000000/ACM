#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define LL long long 
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
using namespace std;
const int maxn=2e5+5;
const LL INF=1e18;
struct Node{
	LL sum;
	LL max;
	LL min;
	LL lazy;
	LL alt;
}seg[maxn*4];
LL arr[maxn];

void pushup(int rt){
	seg[rt].sum=seg[rt<<1].sum+seg[rt<<1|1].sum;
	seg[rt].max=max(seg[rt<<1].max,seg[rt<<1|1].max);
	seg[rt].min=min(seg[rt<<1].min,seg[rt<<1|1].min);
}

void pushdown(int rt,int l,int r){
	if (seg[rt].alt){
		int mid=(l+r)>>1;
		seg[rt<<1].alt=seg[rt<<1|1].alt=1;
		seg[rt<<1].lazy=seg[rt<<1|1].lazy=seg[rt].lazy;
		seg[rt<<1].sum=seg[rt].lazy*(mid-l+1);	seg[rt<<1|1].sum=seg[rt].lazy*(r-mid);
		seg[rt<<1].max=seg[rt<<1|1].max=seg[rt].lazy;
		seg[rt<<1].min=seg[rt<<1|1].min=seg[rt].lazy;
		seg[rt].lazy=seg[rt].alt=0;
	}
	else if (seg[rt].lazy){
		int mid=(l+r)>>1;
		seg[rt<<1].lazy+=seg[rt].lazy;	seg[rt<<1|1].lazy+=seg[rt].lazy;
		seg[rt<<1].sum+=seg[rt].lazy*(mid-l+1);	seg[rt<<1|1].sum+=seg[rt].lazy*(r-mid);
		seg[rt<<1].max+=seg[rt].lazy;	seg[rt<<1|1].max+=seg[rt].lazy;
		seg[rt<<1].min+=seg[rt].lazy;	seg[rt<<1|1].min+=seg[rt].lazy;
		seg[rt].lazy=0;
	}
}

void build(int rt,int l,int r){
	if (l==r){
		seg[rt].sum=seg[rt].max=seg[rt].min=arr[l];
		return;	
	}
	int mid=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}

void update1(int rt,int l,int r,int L,int R,int x){
	if (L<=l&&r<=R){
		seg[rt].lazy+=x;
		seg[rt].sum+=x*(r-l+1);	seg[rt].max+=x;	seg[rt].min+=x;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(rt,l,r);
	if (mid>=L) update1(lson,L,R,x);
	if (mid<R) update1(rson,L,R,x);
	pushup(rt);
}

void update2(int rt,int l,int r,int L,int R,int x){
	if (L<=l&&r<=R){
		seg[rt].alt=1;
		seg[rt].lazy=x;
		seg[rt].sum=x*(r-l+1);	seg[rt].max=x;	seg[rt].min=x;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(rt,l,r);
	if (mid>=L) update2(lson,L,R,x);
	if (mid<R) update2(rson,L,R,x);
	pushup(rt);
}

LL queryMax(int rt,int l,int r,int L,int R){
	if (L<=l&&r<=R){
		return seg[rt].max;
	}
	int mid=(l+r)>>1;
	pushdown(rt,l,r);
	LL ans=-INF;
	if (mid>=L) ans=max(ans,queryMax(lson,L,R));
	if (mid<R) ans=max(ans,queryMax(rson,L,R));
	return ans;
}

LL queryMin(int rt,int l,int r,int L,int R){
	if (L<=l&&r<=R){
		return seg[rt].min;
	}
	int mid=(l+r)>>1;
	pushdown(rt,l,r);
	LL ans=INF;
	if (mid>=L) ans=min(ans,queryMin(lson,L,R));
	if (mid<R) ans=min(ans,queryMin(rson,L,R));
	return ans;
}

LL querySum(int rt,int l,int r,int L,int R){
	if (L<=l&&r<=R){
		return seg[rt].sum;
	}
	int mid=(l+r)>>1;
	pushdown(rt,l,r);
	LL ans=0;
	if (mid>=L) ans+=querySum(lson,L,R);
	if (mid<R) ans+=querySum(rson,L,R);
	return ans;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	build(1,1,n);

}

