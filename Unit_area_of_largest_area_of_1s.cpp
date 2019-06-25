void dfs(int a[SIZE][SIZE],int n,int m,int i,int j, int &c)
{
    if(i>=0 && i<n && j>=0 && j<m)
    {  if(a[i][j]==1)
        {   c++;
            a[i][j]=0;
            dfs(a,n,m,i-1,j-1,c);
            dfs(a,n,m,i-1,j,c);
            dfs(a,n,m,i-1,j+1,c);
            dfs(a,n,m,i,j+1,c);
            dfs(a,n,m,i+1,j+1,c);
            dfs(a,n,m,i+1,j,c);
            dfs(a,n,m,i+1,j-1,c);
            dfs(a,n,m,i,j-1,c);
            
        }
    }
    else
    {
        return;
    }
}



int findAreaUtil(int n, int m, int g[SIZE][SIZE], bool vis[SIZE][SIZE]){
    
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int count=0;
            if(g[i][j]==1)
            {  // cout<<".."<<endl;
                dfs(g,n,m,i,j,count);
                if(ans<count)
                {
                    ans=count;
                }
            }
        }
    }return ans;
    
}
