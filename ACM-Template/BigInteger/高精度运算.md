[TOC]

### String实现高精度加减

```c++
#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

string pls(string a, string b) // a+b(a>0 && b>0)
{
    string res = "";
    while (a[0] == '0') a.erase(0, 1); //clear leading zeros
    while (b[0] == '0') b.erase(0, 1);
    
    int la = a.size(), lb = b.size();
    if (la == 0 && lb == 0) return("0");
    
    reverse(a.begin(), a.end());  
    reverse(b.begin(), b.end());  
    
    int up = 0, L = max(la, lb);
    if (la < L) while (la < L) a += '0', la++; // append leading zeros
    if (lb < L) while (lb < L) b += '0', lb++;
    
    int tmpa, tmpb;
    for (int i = 0; i < L; i++)
    {
        tmpa = a[i] - '0'; tmpb = b[i] - '0';
        res += (char)((up + tmpa + tmpb) % 10 + '0');
        up = (up + tmpa + tmpb) / 10;
    }
    if (up) res += (char)(up + '0');
    reverse(res.begin(), res.end());
    return res;
}

// string res=pls(a,b);

string mis(string a, string b) // a-b (a>0 && b>0)
{
    string res = "";
    while (a[0] == '0') a.erase(0, 1); //clear leading zeros
    while (b[0] == '0') b.erase(0, 1);
    
    int la = a.size(), lb = b.size(), flg = 0;
    if (la < lb || (la == lb && a < b)) // let a > b
    {
        swap(a, b);
        swap(la, lb);
        flg = 1;
    } 
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    int L = max(la, lb);
    if (la < L) while (la < L) a+='0', la++; // append leading zeros
    if (lb < L) while (lb < L) b+='0', lb++;
    
    for (int i = 0; i < L; i++)
    {
        int tmp = a[i] - b[i];
        if (tmp < 0) a[i + 1]--, tmp += 10;
        res += (char)(tmp + '0');
    }
    
    while (L > 1 && res[L - 1]=='0') res.erase(--L, 1); //clear leading zeros
    if (flg) res += "-";
    reverse(res.begin(), res.end());
    return res;
}

//string res=mis(a,b);


int main()
{
    string a,b;
    cin >> a >> b;
    cout << pls(a,b) << endl;
    cout << mis(a,b) << endl;
    return 0;
}
```