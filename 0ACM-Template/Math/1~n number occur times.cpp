
// logn
vector<LL> solve(LL n) {
    vector<LL> res(10, 0);
    if(!n) return res;
    if(n % 10 < 9) {
        res = solve(n - 1);
        while(n) {
            res[n % 10]++;
            n /= 10;
        }
        return res;
    }
    res = solve(n / 10);
    for(int i = 0; i < 10; i++) res[i] = res[i] * 10 + n / 10 + (i > 0);
    return res;
}
