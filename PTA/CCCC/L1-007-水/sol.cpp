#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
string s[11], t;
int main()
{
	s[0] = "ling"; s[1] = "yi";
	s[2] = "er"; s[3] = "san"; s[4] = "si"; s[5] = "wu";
	s[6] = "liu"; s[7] = "qi"; s[8] = "ba"; s[9] = "jiu";
	s[10] = "fu";
	cin >> t;
	int L = t.length();
	for (int i = 0; i < L; i++)
	{
		int tmp = t[i] - '0';
		if (t[i] == '-') tmp = 10;
		cout << s[tmp];
		if (i < L - 1) cout << " ";
	}
	return 0;
}
