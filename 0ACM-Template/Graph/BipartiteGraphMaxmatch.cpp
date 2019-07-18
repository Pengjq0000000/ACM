int dfs(int u)
{
    for(int i = 0; i < E[u].size(); i++)
    {
        int v = E[u][i];
        if(!vis[v])
        {
            vis[v] = 1;
            if(!match[v] || dfs(match[v]))
            {
                match[v] = u;
                return(1);
            }
        }
    }
    return(0);
}

int maxmatch()
{
    int ans = 0;
    MEM(match, 0);
    for(int i = 1; i <= n; i++)
    {
        MEM(vis, 0);
        ans += dfs(i);
    }
    return(ans);
}
