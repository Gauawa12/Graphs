void dfs(vector<int> a[], int n, int m,int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<m )
    {
        if(a[i][j]==1)
        {
            a[i][j]=0;
            dfs(a,n,m,i-1,j-1);
            dfs(a,n,m,i-1,j);
            dfs(a,n,m,i-1,j+1);
            dfs(a,n,m,i,j+1);
            dfs(a,n,m,i+1,j+1);
            dfs(a,n,m,i+1,j);
            dfs(a,n,m,i+1,j-1);
            dfs(a,n,m,i,j-1);
            
        }
    }
}



int findIslands(vector<int> A[], int n, int m)
{
    
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==1)
            {
                dfs(A,n,m,i,j);
                count++;
            }
        }
    }
    return count;
    
}

