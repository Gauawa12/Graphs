#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&v,int n,int i,int j,bool &ans)
{
    if(i>=1 && i<=n && j>=1 && j<=n && (v[i][j]==3 || v[i][j]==1))
    {   
        v[i][j]=-1;
        
        if(v[i+1][j]==2 || v[i-1][j]==2 || v[i][j+1]==2 || v[i][j-1]==2)
        {
            ans=true;
            return;
        }
        
            dfs(v,n,i+1,j,ans);
            dfs(v,n,i-1,j,ans);
            dfs(v,n,i,j+1,ans);
            dfs(v,n,i,j-1,ans);
            return;
        
    }
    else
    {
        return;
    }
}




int main() {
	int t;
	cin>>t;
	while(t--)
	{   
	    int si,sj;
	    int n;
	    cin>>n;
	    n=n+2;
	   vector<vector<int> >v(n,vector<int>(n,-1));
	   // int v[n][n];
	    for(int i=1;i<n-1;i++)
	    {
	        for(int j=1;j<n-1;j++)
	        {
	            cin>>v[i][j];
	            if(v[i][j]==1)
	            {
	                si=i;sj=j;
	            }
	        }
	    }
	    
	    bool ans=false;
	   dfs(v,n,si,sj,ans);
	    if(ans)
	    {
	        cout<<"1"<<endl;
	    }
	    else
	    {
	        cout<<"0"<<endl;
	    }
	    
	    
	}
	return 0;
}
