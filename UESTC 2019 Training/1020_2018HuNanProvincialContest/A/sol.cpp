#include<bits/stdc++.h>
using namespace std;
string t[5][6];
int main()
{
    t[1][1] = "ooo"; t[2][1] = "ooo"; t[3][1] = "ooo"; t[4][1] = "ooo";
    t[1][2] = "..o"; t[2][2] = "o.o"; t[3][2] = ".o."; t[4][2] = "o.o";
    t[1][3] = "ooo"; t[2][3] = "o.o"; t[3][3] = ".o."; t[4][3] = "ooo";
    t[1][4] = "o.."; t[2][4] = "o.o"; t[3][4] = ".o."; t[4][4] = "o.o";
    t[1][5] = "ooo"; t[2][5] = "ooo"; t[3][5] = "ooo"; t[4][5] = "ooo";
    int w; cin >> w;
    for (int j = 1; j <= 5; j++)
    {
        for (int i = 1; i <= 4; i++)
        {
            if (i > 1) for (int k = 1; k <= w; k++) cout << '.';
            cout << t[i][j];
        }
        cout << '\n';
    }
    return 0;
}