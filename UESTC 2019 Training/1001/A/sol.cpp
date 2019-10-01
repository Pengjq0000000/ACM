#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int cnt = 0;
        for (int i = 0; i < 4; i++) 
        {
            scanf("%d", &a[i]);
            if (a[i] > 0) cnt++;
        }
        if (cnt == 0) puts("Typically Otaku");
        else if (cnt == 1) puts("Eye-opener");
        else if (cnt == 2) puts("Young Traveller");
        else if (cnt == 3) puts("Excellent Traveller");
        else puts("Contemporary Xu Xiake");
    }
    return 0;
}