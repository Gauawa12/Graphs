void dijkstra(vector<vector<int>> g, int src, int v)
{
    vector<int>dist(v,INT_MAX);
    dist[src]=0;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
    pq.push(make_pair(0,src));
    
    while(!pq.empty())
    {
        int t=pq.top().second;
        pq.pop();
        for(int i=0;i<v;i++)
        {
            int w=g[t][i];
            if(dist[i]>dist[t]+w)
            {
                dist[i]=dist[t]+w;
                pq.push(make_pair(dist[i],i));
            }
        }
    }
    
    for(auto x:dist)
    {
        cout<<x<<" ";
    }
}
