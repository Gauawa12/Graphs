nt* topoSort(int v, vector<int> adj[])
{
    vector<int>zino(v,0);
    for(int i=0;i<v;i++)
    {
        for(auto x:adj[i])
        {
            zino[x]++;
        }
    }
    queue<int>q;
    stack<int>s;
    for(auto i=0;i<zino.size();i++)
    {
        if(zino[i]==0)
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        s.push(t);
        
        for(auto x:adj[t])
        {
            q.push(x);
        }
    }
    vector<bool>vis(v);
    int *ans=new int[v];
    int i=v-1;
    while(!s.empty() && i>=0)
    {
        int t=s.top();
        if(!vis[t])
        {
            ans[i]=t;
            i--;
            vis[t]=true;
        }
        s.pop();
    }
    
    return ans;
    
}

