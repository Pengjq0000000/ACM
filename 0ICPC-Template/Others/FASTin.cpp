namespace IO
{
    int aa; bool bb; char ch;
    int input()
    {
        while(ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
        ch == '-' ? (bb = 1, aa = 0) : (bb = 0, aa = ch - '0');
        while(ch = getchar(), (ch >= '0' && ch <= '9'))
            aa = aa * 10 + ch - '0';
        return (bb ? (-aa) : (aa));
    }
    void print(int x)
    {
        if (x == 0) return;
        if (x >= 10) print(x / 10);
        putchar('0' + x % 10);
    }
    void output(int x)
    {
        if (x < 0) putchar('-'), x = -x;
        if (x == 0) putchar('0');
        else print(x);
    }
}