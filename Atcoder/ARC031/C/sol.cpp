#include<bits/stdc++.h>
using namespace std;
vector<int> gen1(int n)
{  
    vector<int>bs1, bs2, bs3;
    bs1 = {0, 1, 3, 2};
    bs2 = {2, 0, 1, 3};
    bs3 = {3, 1, 0, 2};
    vector<int>res = {0, 1}, temp;
    for (int x = 1; x < n; x += 2)
    {  
        temp.clear();
        for (int high : bs1) temp.push_back(high << x | res[0]);
        for (int high : bs2) temp.push_back(high << x | res[1]);
        for (int i = 2; i < (int)res.size(); i += 2)
        {
            for (int high : bs3) temp.push_back(high << x | res[i]);
            for (int high : bs2) temp.push_back(high << x | res[i + 1]);
        }
        res = temp;
    }
    for (int i = 0; i < (int)res.size() - 1; i++) assert(__builtin_popcount(res[i] ^ res[i + 1]) == 1);
    assert(*res.begin() == 0 && *res.rbegin() == (1 << n) - 1);
    return res;
}
vector<int> gen2(int n)
{
    vector<int>res = {0, 1}, temp;
    if (n == 0) return {0};
    for (int x = 1; x < n; x++)
    {
        temp.clear();
        for (int low : res) temp.push_back(low);
        reverse(res.begin(), res.end());
        for (int low : res) temp.push_back((1 << x) | low);
        res = temp;
    }
    for (int i = 0; i < (int)res.size() - 1; i++) assert(__builtin_popcount(res[i] ^ res[i + 1]) == 1);
    assert(*res.begin() == 0);
    return res;
}
vector<int> gen3(int cnt0, int cnt1)
{
    vector<int>part1 = gen1(cnt1);
    vector<int>part0 = gen2(cnt0);
    vector<int>res;
    for (int low : part1)
    {
        for (int high : part0) res.push_back(high << cnt1 | low);
        reverse(part0.begin(), part0.end()); 
    }
    for (int i = 0; i < (int)res.size() - 1; i++) assert(__builtin_popcount(res[i] ^ res[i + 1]) == 1);
    assert(*res.begin() == 0 && *res.rbegin() == (1 << cnt1) - 1);
    return res;
}
int id[2][20], cnt0, cnt1;
int main()
{
    int n, A, B; scanf("%d%d%d", &n, &A, &B);
    B ^= A; 
    if (!(__builtin_popcount(B) & 1)) {puts("NO"); return 0;}
    for (int i = 0; i < n; i++)
    {
        if (B >> i & 1) id[1][cnt1++] = i;
        else id[0][cnt0++] = i;
    }
    vector<int>temp = gen3(cnt0, cnt1);
    puts("YES");
    for (int x : temp)
    {
        int res = 0;
        for (int i = 0; i < cnt0; i++) if (x >> (cnt1 + i) & 1) 
            res += (1 << id[0][i]);
        for (int i = 0; i < cnt1; i++) if (x >> i & 1)
            res += (1 << id[1][i]);
        printf("%d ", res ^ A);
    }
    puts("");
    return 0;
}