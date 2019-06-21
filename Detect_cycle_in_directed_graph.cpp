
bool dfs(vector<int> adj[],int v,int s,vector<bool>&vis,vector<bool>&ances)
{
    vis[s]=true;
    ances[s]=true;
    
    for(auto x:adj[s])
    {
        if(ances[x])
        {
            return true;
        }
        if(!vis[x] && dfs(adj,v,x,vis,ances))
        {
            return true;
        }
    }
    ances[s]=false;
    return false;
    
}




bool isCyclic(int v, vector<int> adj[])
{
    vector<bool>vis(v,false),ances(v,false);
    
    for(int i=0;i<v;i++)
    {
        if(!vis[i] && dfs(adj,v,i,vis,ances))
        {
            return true;
        }
        
    }
    
    return false;
}
