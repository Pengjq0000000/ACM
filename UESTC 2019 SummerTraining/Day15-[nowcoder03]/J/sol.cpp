#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
unordered_map<LL, int>pos, cnt;
int pre[maxn], nxt[maxn], v[maxn];
char s[20];
LL name[maxn];
LL get_h(char *s, int base)
{
    LL tmp = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) tmp = tmp * base + (s[i] - '0' + 1);
    return tmp;
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        cnt.clear(); pos.clear();
        int m, up; scanf("%d%d", &m, &up);
        int head = 0, tail = 1;
        for (int i = 0; i <= m; i++) pre[i] = nxt[i] = 0;
        int tot = 0;
        //nxt[0]=1;pre[1]=0;
        while (m--)
        {
            int op, val; scanf("%d %s %d", &op, s, &val);
            LL hval = get_h(s, 12);
            //printf("hval:%lld\n", hval); //
            if (op == 0)
            {
                if (!cnt.count(hval))
                {
                    pre[tail] = tail - 1;
                    nxt[tail - 1] = tail;
                    pos[hval] = tail;
                    cnt[hval]++;
                    v[tail] = val;
                    name[tail] = hval;
                    nxt[tail] = tail + 1;
                    tail++;
                    if (tot < up) tot++;
                    else 
                    {
                        cnt.erase(name[nxt[head]]);
                        head = nxt[head];
                    }
                    printf("%d\n", val);
                } 
                else 
                {
                    int p = pos[hval]; printf("%d\n", v[p]);
                    if (p == tail - 1) continue;
                    nxt[pre[p]] = nxt[p];
                    pre[nxt[p]] = pre[p];
                    pre[tail] = tail - 1;
                    nxt[tail - 1] = tail;
                    pos[hval] = tail;
                    v[tail] = v[p];
                    name[tail] = hval;
                    nxt[tail] = tail + 1;
                    tail++;
                }
            }
            else 
            {
                if (!cnt.count(hval)) printf("Invalid\n");
                else 
                {
                    int p = pos[hval];
                    if (val == -1)
                    {
                        if (pre[p] == head) printf("Invalid\n");
                        else printf("%d\n", v[pre[p]]);
                    }
                    else if (val == 0) printf("%d\n", v[p]);
                    else if (val == 1)
                    {
                        if (nxt[p] == tail) printf("Invalid\n");
                        else printf("%d\n", v[nxt[p]]);
                    }
                }
            }
        }
    }
	return 0;
}
