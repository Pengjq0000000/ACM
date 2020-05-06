    #include<bits/stdc++.h>
    using namespace std;
    void deal(int i, int j){
        while (i < j) printf("%d %d\n", i++, j--);
    }
    int main(){
        int n, m; scanf("%d%d", &n, &m);
        deal(1, 1 + m / 2 * 2);
        deal(1 + m / 2 * 2 + 1, 1 + m / 2 * 2 + 1 + (m - m / 2) * 2 - 1);
        return 0;
    }