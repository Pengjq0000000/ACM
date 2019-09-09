int get(int y, int m, int d)
{
    int res;
    if (m == 1 || m == 2) m += 12, y--;
    res = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
    res = (res + 7) % 7;
    return res;
}
