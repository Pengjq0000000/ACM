#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
map<string, int> id;
string table[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
int main()
{
    for (int i = 0; i < 5; i++) id[table[i]] = i;
    int T; scanf("%d", &T);
    while (T--)
    {
	    LL y1, y2, m1, m2, d1, d2;
        string s;
        cin >> y1 >> m1 >> d1 >> s;
        cin >> y2 >> m2 >> d2;
        int now = id[s];
        LL dt = (y2 - y1) * 300 + (m2 - m1) * 30 + (d2 - d1);
        dt %= 5;
        cout << table[(now + dt + 5) % 5] << endl;
    }
	return 0;
}
