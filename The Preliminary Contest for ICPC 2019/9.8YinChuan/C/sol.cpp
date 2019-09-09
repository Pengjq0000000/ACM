#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
struct node{int a, b;}t[1000];
bool cmp1(node x, node y) {return x.a > y.a;}
bool cmp2(node x, node y) {return y.b > y.b;}
void dfs(int now)
{

}
int n;
int main()
{
	scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &t[i].a, &t[i].b);
	return 0;
}
