

// For each node cycle is checked because the graph may by disconnected
bool cyclic(vector<int> adj[],int v,int s)
{
    queue<int>q;
    q.push(s);
    vector<bool>vis(v);
    
    vis[s]=true;
    vector<int>pnt(v,-1);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        
        vis[t]=true;
        
        for(auto x:adj[t])
        {
            if(!vis[x])
            {
                q.push(x);
                vis[x]=true;
                pnt[x]=t;
            }
            else if(vis[x] && x!=pnt[t])
            {
                return true;
            }
        }
    }
    
    return false;
}



bool isCyclic(vector<int> adj[], int v)
{
   for(int i=0;i<v;i++)
   {
       if(cyclic(adj,v,i))
       {
           return true;
       }
   }
   return false;
   
}


// Optimized approach once a group is traversed it is not traversed again

bool cyclic(vector<int> adj[],int v,int s, vector<bool>vis)
{
    queue<int>q;
    q.push(s);
    //vector<bool>vis(v);
    
    vis[s]=true;
    vector<int>pnt(v,-1);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        
        vis[t]=true;
        
        for(auto x:adj[t])
        {
            if(!vis[x])
            {
                q.push(x);
                vis[x]=true;
                pnt[x]=t;
            }
            else if(vis[x] && x!=pnt[t])
            {
                return true;
            }
        }
    }
    
    return false;
}



bool isCyclic(vector<int> adj[], int v)
{   
    vector<bool>visited(v);
    
   for(int i=0;i<v;i++)
   {
       if(!visited[i] && cyclic(adj,v,i,visited))
       {
           return true;
       }
   }
   return false;
   
}


