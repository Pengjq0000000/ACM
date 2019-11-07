#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 7;
int na, nb, nc; 
int A[N], B[N], C[N], d, tot;
ll ans, temp;
int numC[N];
vector<int>vec;
int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
int cntA[N * 3], cntB[N * 3], cntC[N * 3];
void cal(int *A, int *B, int *C)
{
    for (int i = 1; i <= tot; i++) cntB[i] = 0;
    for (int i = 1; i <= nb; i++) cntB[getid(B[i])]++;
    temp = 0;
    for (int i = 1, l = 1, r = 0; i <= na; i++) 
    {
        // [A[i] - d, A[i])
        while (r < nc && C[r + 1] < A[i]) r++;
        while (l <= nc && C[l] < A[i] - d) l++;
        numC[i] = max(0, r - l + 1);
        int x = getid(A[i]);
        if (cntB[x] > 0) ans += (ll)cntB[x] * numC[i];
    }
    for (int i = 1, l = 1, r = 0; i <= nb; i++)
    {
        // (B[i], B[i] + d]
        while (r < na && A[r + 1] <= B[i] + d) temp += numC[++r];
        while (l <= na && A[l] <= B[i]) temp -= numC[l++];
        //printf("l = %d r = %d\n", l, r);
        ans += temp;
    }

}
int main()
{
    A[0] = B[0] = C[0] = -(2e9 + 7);
    int x, y, z;
    while (scanf("%d%d%d%d", &d, &x, &y, &z) == 4)
    {
        vec.clear();
        for (int i = 1; i <= x; i++) scanf("%d", &A[i]), vec.push_back(A[i]); 
        for (int i = 1; i <= y; i++) scanf("%d", &B[i]), vec.push_back(B[i]);
        for (int i = 1; i <= z; i++) scanf("%d", &C[i]), vec.push_back(C[i]);
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        tot = vec.size();
        ans = 0;
        na = x; nb = y; nc = z; cal(A, B, C); 
        na = y; nb = z; nc = x; cal(B, C, A); 
        na = z; nb = x; nc = y; cal(C, A, B);
        for (int i = 1; i <= tot; i++) cntA[i] = cntB[i] = 0;
        for (int i = 1; i <= x; i++) cntA[getid(A[i])]++;
        for (int i = 1; i <= y; i++) cntB[getid(B[i])]++;
        for (int i = 1; i <= z; i++)
        {
            int x = getid(C[i]);
            ans += (ll)cntA[x] * cntB[x];
        }
        
        printf("%lld\n", ans);
    }
    return 0;
}