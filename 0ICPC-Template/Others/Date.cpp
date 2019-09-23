int zeller(int y, int m, int d) // 输入年月日得到是星期几
{
    int res;
    if (m == 1 || m == 2) m += 12, y--;
    res = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
    res = (res + 7) % 7;
    return res;
}
int getid(int y, int m, int d) // 输入年月日得到id值，通常用于作差求两个日期间间隔几天
{
    if (m < 3) m += 12, y--;
    return 365 * y + y / 4 - y / 100 + (153 * m + 2) / 5 + d;
}
