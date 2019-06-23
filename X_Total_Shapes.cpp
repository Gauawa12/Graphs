#include<bits/stdc++.h>
#include<iostream>
using namespace std;


void dfs(vector<string>&s,int n,int m,int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<m)
    {
        if(s[i][j]=='X')
        {
            s[i][j]='O';
            dfs(s,n,m,i+1,j);
            dfs(s,n,m,i-1,j);
            dfs(s,n,m,i,j+1);
            dfs(s,n,m,i,j-1);
        }
    }
    
}


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    
	    vector<string>s(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>s[i];
	    }
	    
	    int count=0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(s[i][j]=='X')
	            {   
	                count++;
	                dfs(s,n,m,i,j);
	            }
	        }
	    }
	    
	    cout<<count<<endl;
	}
	return 0;
}
