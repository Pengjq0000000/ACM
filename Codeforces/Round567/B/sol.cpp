#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int num[maxn];

string pls(string a,string b) // a+b(a>0 && b>0)
{
    string res="";
    while (a[0]=='0') a.erase(0,1); //clear leading zeros
    while (b[0]=='0') b.erase(0,1);
    
    int la=a.size(),lb=b.size();
    if (la==0 && lb==0) return("0");
    
    reverse(a.begin(),a.end());  
    reverse(b.begin(),b.end());  
    
    int up=0,L=max(la,lb);
    if (la<L) while (la<L) a+='0',la++; // append leading zeros
    if (lb<L) while (lb<L) b+='0',lb++;
    
    int tmpa,tmpb;
    for (int i=0;i<L;i++)
    {
        tmpa=a[i]-'0';tmpb=b[i]-'0';
        res+=(char)((up+tmpa+tmpb)%10+'0');
        up=(up+tmpa+tmpb)/10;
    }
    if (up) res+=(char)(up+'0');
    reverse(res.begin(),res.end());
    return res;
}

string s;
vector<int>pos;
int main()
{
	STREAM_FAST;
	int n; cin >> n;
	cin >> s;
	int L = s.length();
	int tmp = n;
	for (int i = 0; i < L - 1; i++)
	{
		if (s[i + 1] != '0')
		{
			int t = max(i + 1, L - i - 1);
			if (t < tmp)
			{
				pos.clear();
				pos.pb(i);
				tmp = t;
			}
			else if (tmp == t) pos.pb(i);
		}
	}
	string ans = "";
	for (int x : pos)
	{

		string a = "", b = "", res = "";
		for (int i = 0; i <= x; i++) a += s[i];
		for (int i = x + 1; i < L; i++) b += s[i];
		res = pls(a, b);  
		if (ans == "") ans = res;
		else if (ans.size() > res.size() || (ans.size() == res.size() && ans > res)) ans = res;
	}
	cout << ans << endl;
	return 0;
}
