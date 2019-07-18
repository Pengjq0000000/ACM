// arr_index: 0 ~ n - 1 where n == 2 ^ k
void fwt(int *a, int n)
{
    for (int k = 1; k < n; k <<= 1)
        for (int m = k << 1, i = 0; i < n; i += m)
            for (int j = 0; j < k; j++)
            {
                int x = a[i + j], y = a[i + j + k];
                // ^ : a[i + j] = x + y, a[i + j + k] = x - y;
                // & : a[i + j] = x + y;
                // | : a[i + j + k] = x + y;
            }
}
void ifwt(int *a, int n)
{
    for (int k = 1; k < n; k <<= 1)
        for (int m = k << 1, i = 0; i < n; i += m)
            for (int j = 0; j < k; j++)
            {
                int x = a[i + j], y = a[i + j + k];
                // ^ : a[i + j] = (x + y) / 2, a[i + j + k] = (x - y) / 2;
                // & : a[i + j] = x - y;
                // | : a[i + j + k] = y - x;
            }
}


	fwt(a, n);
    fwt(b, n);
    inv2 = ksm(2, mod - 2);
    for (int i = 0; i < n; i++) c[i] = MOD(a[i] * b[i]);
    ifwt(c, tot);


