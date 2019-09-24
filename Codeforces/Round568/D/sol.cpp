#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e5 + 7;
struct node
{
	int id; LL val;
	node(int id, LL val):id(id), val(val){}
	node(){}
	bool operator < (const node &rhs) const
	{
		if (val == rhs.val) return id < rhs.id;
		return val < rhs.val;
	} 
}a[maxn];
vector<node>v;
LL det[maxn];
map<LL, int>cnt;
vector<LL>num;
int main()
{
	int n; scanf("%d", &n);
	if (n <= 3) 
	{
		puts("1");
		return 0;
	} 
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i].val), a[i].id = i;
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++)
	{
		det[i] = a[i].val - a[i - 1].val;
		if (!cnt.count(det[i])) num.pb(det[i]);
		cnt[det[i]]++;
	}
	if (num.size() == 1)
	{
		printf("%d\n", a[1].id); return 0;
	}
	if (num.size() == 2)
	{
		if (cnt[num[0]] == 1 || cnt[num[1]] == 1)
		{
			LL x;
			if (cnt[num[0]] == 1) x = num[0];else x = num[1];
			if (x == 0)
			{
				for (int i = 2; i <= n; i++) 
					if (a[i].val == a[i - 1].val) 
					{
						printf("%d\n", a[i].id);
						return 0;
					}
			}
			if (a[2].val - a[1].val == x)
			{
				printf("%d\n", a[1].id);
				return 0;
			}
			else if (a[n].val - a[n - 1].val == x)
			{
				printf("%d\n", a[n].id);
				return 0;
			}
			else 
			{
				puts("-1"); return 0;
			}
		}
		else if (cnt[num[0]] == 2 || cnt[num[1]] == 2)
		{
			LL x, y; 
			if (cnt[num[0]] == 2) 
			{
				x = num[0]; 
				y = num[1];
			}
			else 
			{
				x = num[1];
				y = num[0];
			}
			if (cnt[num[0]] == 2 && cnt[num[1]] == 2) 
			{
				x = min(num[0], num[1]);
				y = max(num[0], num[1]);
			}
			if (x + x != y) 
			{
				puts("-1");
				return 0;
			}
			for (int i = 3; i <= n; i++)
			{
				if (a[i].val - a[i - 1].val == x && a[i - 1].val - a[i - 2].val == x)
				{
					printf("%d\n", a[i - 1].id);
					return 0;
				}
			}
			puts("-1"); return 0;
		}
		puts("-1"); return 0;
	}
	else if (num.size() == 3)
	{
		int cnt1 = cnt[num[0]], cnt2 = cnt[num[1]], cnt3 = cnt[num[2]];
		if ((cnt1 == 1 && cnt2 == 1) || (cnt2 == 1 && cnt3 == 1) || (cnt1 == 1 && cnt3 == 1))
		{
			for (int i = 4; i <= n; i++)
			{
				if (a[i].val - a[i - 2].val == a[i - 2].val - a[i - 3].val && cnt[det[i]] == 1 && cnt[det[i - 1]] == 1)
				{
					printf("%d\n", a[i - 1].id);
					return 0;
				}
				
				if (a[i].val - a[i - 1].val == a[i - 1].val - a[i - 3].val && cnt[det[i - 1]] == 1 && cnt[det[i - 2]] == 1)
				{
					printf("%d\n", a[i - 2].id);
					return 0;
				}	
			}
		}
		puts("-1"); return 0;
	}
	puts("-1");
	return 0;
}
