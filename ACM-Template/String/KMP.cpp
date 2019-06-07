/*------------------------------------------------------------------------*/

// KMP
const int maxn = 1e5+7;

struct Kmp
{
    int nex[maxn],n,m;
    void GetNext(char *p)
    {
        m=strlen(p);
        memset(nex,0,sizeof(nex));
        nex[0]=-1;
        int k=-1,j=0;
        while (j<m)
        {
            if (k==-1 || p[j]==p[k]) nex[++j]=++k;
            else k=nex[k];
        }
    }
    int match(char *s,char *p)
    {
        n=strlen(s),m=strlen(p);
        int i=0,j=0,cnt=0;
        while (i<n && j<m)
        {
            if (j==-1 || s[i]==p[j]) i++,j++;
            else j=nex[j];
            if (j==m) //successfully match
            {
                j=nex[j]; // cross(s=aaaa p=aa cnt=3)
                //j=0;    // non-cross(s=aaaa p=aa cnt=2)
                cout<<i<<endl; 
                // match point:the i-th(starting from 1) of s
                cnt++;// match counts
            }
        }
        return cnt;
    }
}KMP;

/*------------------------------------------------------------------------*/



