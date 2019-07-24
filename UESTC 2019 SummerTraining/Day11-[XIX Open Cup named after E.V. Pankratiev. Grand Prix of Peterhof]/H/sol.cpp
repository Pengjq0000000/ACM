#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int gettttt()
{
    int x; scanf("%d", &x);
    return x;
}
void puttttt(char x)
{
    if (x == '>') x = '<';
    else if (x == '<') x = '>';
    printf("%c\n", x);
    fflush(stdout);
}
int main()
{
	int l = 1, r = 1e9;
    int cnt = 0;
    while (1)
    {
        //int mid = (L + R) / 2;
        //int x = mid;
        int x = gettttt();
        cnt++;
        //printf("cnt-%d:", cnt);
        if (x < l) 
        {
            puttttt('<');
            if (cnt == 100) break; 
            continue;
        }
        else if (x > r) 
        {
            puttttt('>');
            if (cnt == 100) break; 
            continue;
        }
        if (l == x && r == x)
        {
            puttttt('=');
            break;
        }
        int len1 = x - l, len2 = r - x;
        if (len1 > len2)
        {
            puttttt('>');
            r = x - 1;
            //R = mid;
        }
        else 
        {
            puttttt('<');
            l = x + 1;
            //L = mid + 1;
        }
        if (cnt == 100) break;
    }
	return 0;
}
