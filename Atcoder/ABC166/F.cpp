#include<bits/stdc++.h>
using namespace std;
char s[100010][2];
int a[3];
vector<char>ans;
int main(){
    int n; scanf("%d%d%d%d", &n, &a[0], &a[1], &a[2]);
    for (int i = 1; i <= n; i++) scanf(" %s", s[i]), s[i][0] -= 'A', s[i][1] -= 'A';
    for (int i = 1; i <= n; i++){
        char cx = s[i][0], cy = s[i][1];
        int &x = a[cx];
        int &y = a[cy];
        if (x == 0 && y == 0){
            puts("No");
            return 0;
        }
        if (x > y) x--, y++, ans.push_back('A' + cy);
        else if (x < y) y--, x++, ans.push_back('A' + cx);
        else {
            char nx = s[i + 1][0], ny = s[i + 1][1];
            if (i == n || (i < n && nx == cx && ny == cy)) x--, y++, ans.push_back('A' + s[i][1]);
            else {
                if (cx == nx || cx == ny) y--, x++, ans.push_back('A' + cx);
                else if (cy == nx || cy == ny) x--, y++, ans.push_back('A' + cy);
            }
        }
        assert(a[0] >= 0 && a[1] >= 0 && a[2] >= 0);
    }
    puts("Yes");
    for (char ch : ans) printf("%c\n", ch);
    return 0;
}