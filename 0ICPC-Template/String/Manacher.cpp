/*------------------------------------------------------------------------*/

// Manacher
int r[maxn], a[maxn];
char s[maxn];
// r[i] means maxlength when i is center
int Manacher(int len)
{
	int idx = 0, rig = 0, ans = 1;
	MEM(r, 0);
	for (int i = 0; i <= len; i++)
	{
		if (i <= rig) r[i] = min(r[idx * 2 - i], rig - i);
		while (i > r[i] && i + r[i] < len && a[i - r[i] - 1] == a[i + r[i] + 1]) r[i]++;
		if (i + r[i] > rig) {rig = i + r[i]; idx = i;}
		ans = max(ans, r[i]);
	}
	return ans; // return the max length
}
int main()
{
	scanf("%[^\n]", s);
	int L = strlen(s);
	for (int i = 0; i < L; i++)
	{
		a[i << 1] = -1; // a[i << 1] = '#';
		a[i << 1 | 1] = s[i];
	}
	a[L << 1] = -1;
	printf("%d\n", Manacher(L << 1));
	return 0;
}
/*------------------------------------------------------------------------*/



