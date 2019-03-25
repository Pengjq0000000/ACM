#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
struct node
{
	int num, val;
	node(int num, int val) : num(num), val(val) {}
	node(){}
	bool operator < (const node &rhs) const
	{
		return val < rhs.val;
	}
};
priority_queue<node>hp;
queue<node>q;
int inq[maxn], inhp[maxn], done[maxn];
int a[maxn * 2], v[maxn * 2];
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]); v[i] = a[i] - i;
		a[i + n] = a[i]; v[i + n] = a[i] - n;
	}
	LL ans = 0, qsz = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += abs(v[i]);
		if (v[i] < 0) {hp.push(node(a[i], v[i])); inhp[a[i]] = 1;}
		else {inq[a[i]] = 1; qsz++;}
	}
	int bad = 0; LL res = ans;
	for (int tim = 1; tim <= n; tim++)
	{
		if (inq[a[tim]]) // kick out from queue
		{
			qsz--;
			inq[a[tim]] = 0;
		}
		else if (inhp[a[tim]]) // kick out from heap
		{
			bad++; done[a[tim]] = 1;
			inhp[a[tim]] = 0;
		}
		ans = ans - (abs(v[tim] + tim - 1)) + abs(v[tim + n]); // delete and insert 
		ans = ans + qsz - ((int)hp.size() - bad); // move 
		res = min(ans, res);
		hp.push(node(a[tim + n], v[tim + n] - tim)); // join in the heap
		inhp[a[tim + n]] = 1;
		while (hp.size())
		{
			node tmp = hp.top();
			if (done[tmp.num]) {hp.pop(); bad--; continue;} 
			else if (tmp.val + tim >= 0)
			{
				qsz++;
				inq[tmp.num] = 1; inhp[tmp.num] = 0;
				hp.pop();
			}
			else break;
		}
	}
	printf("%lld\n", res);
	return 0;
}

