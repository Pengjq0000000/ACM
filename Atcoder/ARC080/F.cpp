#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100001;
typedef pair<int, int> pii;

namespace matching {

vector<int> g[N];   //  g[u]:X中顶点$u$的邻接表
bool vis[N];        //  vis[u]:当前dfs中Y中顶点u是否已被访问过
int lnk[N];         //  lnk[u]:Y中顶点u对应的匹配点。若u未被匹配则lnk[u]=0

//  从X顶点u出发寻找增广路
bool dfs(int u) {
    for (int v : g[u]) {
        //  v已被访问过，且无法从v出发找到增广路或增广路的上一个节点是v则跳过
        if (vis[v] || lnk[v] == u) continue;
        //  v未被访问过，标记v
        vis[v] = 1;
        //  v已有匹配点，且无法从v出发找到增广路则跳过
        if (lnk[v] && !dfs(lnk[v])) continue;
        //  v没有匹配点或找到从lnk[v]出发的增广路，则设v的匹配点为u
        lnk[v] = u; return true;
    }
    //  找不到增广路
    return false;
}

//  接口:
//  int nl: X节点数; X中节点编号为[1...nl]
//  int nr: Y节点数; Y中节点编号为[1...nr]
//  const vector<pii>& es: 二分图中的边集。pii的first为X中节点编号，second为Y中节点编号
//  返回值vector<pii> res: 得到的最大匹配。
int match(int nl, int nr, const vector<pii>& es) {
    //  初始化，建图
    for (int i = 1; i <= nl; ++i)
        g[i].clear();
    fill_n(lnk + 1, nr, 0);
    for (pii e : es)
        g[e.first].push_back(e.second);
    //  依次从每个点出发寻找增广路
    for (int i = 1; i <= nl; ++i) {
        fill_n(vis + 1, nr, false);
        dfs(i);
    }
    //  按Y中每个点i的匹配点lnk[i]得到结果
    int res = 0, lx = nl, ly = nr;
    for (int i = 1; i <= nr; ++i)
        if (lnk[i]) res++, lx--, ly--;
    res += lx / 2 * 2; lx -= lx / 2 * 2;
    res += ly / 2 * 2; ly -= ly / 2 * 2;
    assert((lx ^ ly) == 0);
    if (lx && ly) res += 3;
    return res;
}

}

namespace prime
{

const int maxn = 1e7 + 7;
int vis[maxn];
int prime[maxn], mu[maxn], minprim[maxn], tot = 0; //1 ~ tot
void get_prime(int maxl) // get prime <= maxl
{
    minprim[1] = 1;
    for (int i = 2; i <= maxl; i++)
    {
        if (!vis[i])
        {
            prime[++tot] = i; minprim[i] = i;
        }
        for (int j = 1; j <= tot; j++)
        {
            if (i * prime[j] > maxl) break;
            vis[i * prime[j]] = 1;
            minprim[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) 
            {
            	break;
            }
        }
    }
    vis[1] = vis[2] = 1;
    //vis[i] == 0 -> i is a prime
}

}
vector<int>pt;
vector<pii>es;
int x[301], lp[301], rp[301];
int main()
{
    prime::get_prime(1e7 + 5);
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    x[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        if (x[i] - 1 != x[i - 1]) pt.push_back(x[i]);
        if (x[i] + 1 != x[i + 1]) pt.push_back(x[i] + 1);
    }
    sort(pt.begin(), pt.end());
    pt.erase(unique(pt.begin(), pt.end()), pt.end());
    int nl = 0, nr = 0;
    for (int x : pt) if (x % 2) lp[++nl] = x;
    else rp[++nr] = x;
    for (int i = 1; i <= nl; i++)
        for (int j = 1; j <= nr; j++)
        {
            if (!prime::vis[abs(lp[i] - rp[j])]) es.emplace_back(i, j); 
        }
    // for (int x : pt) printf(" %d\n", x);
    printf("%d\n", matching::match(nl, nr, es));
    return 0;   
}