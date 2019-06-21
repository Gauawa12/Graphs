void bfs(int s, vector<int> adj[], bool vis[])
{
    queue<int>q;
    q.push(s);
    vis[s]=true;
    
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        cout<<t<<" ";
        for(auto x:adj[t])
        {
            if(!vis[x])
            {
                q.push(x);
                vis[x]=true;
            }
        }
    }
    
}
