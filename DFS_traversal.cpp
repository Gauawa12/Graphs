void dfs(int s, vector<int> g[], bool vis[])
{
    
    cout<<s<<" ";
    vis[s]=true;
    for(auto x:g[s])
    {
        if(!vis[x])
        {
            dfs(x,g,vis);
        }
    }
}
