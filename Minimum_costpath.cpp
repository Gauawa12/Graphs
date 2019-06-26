#include <bits/stdc++.h>
#define pb push_back;
#define mp make_pair
using namespace std;

void bfs(int **v,int **dp,int n)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push(mp(v[0][0],mp(0,0)));
    
    while(!pq.empty())
    {
        auto t=pq.top().second;
        int i=t.first;
        int j=t.second;
        pq.pop();
        
        if(i+1<n)
        {
            int temp=v[i+1][j];
            if(dp[i+1][j]>dp[i][j]+temp)
            {
                dp[i+1][j]=dp[i][j]+temp;
                pq.push(mp(dp[i+1][j],mp(i+1,j)));
            }
        }
        if(i-1>=0)
        {
            int temp=v[i-1][j];
            if(dp[i-1][j]>dp[i][j]+temp)
            {
                dp[i-1][j]=dp[i][j]+temp;
                pq.push(mp(dp[i-1][j],mp(i-1,j)));
            }
        }
        if(j+1<n)
        {
            int temp=v[i][j+1];
            if(dp[i][j+1]>dp[i][j]+temp)
            {
                dp[i][j+1]=dp[i][j]+temp;
                pq.push(mp(dp[i][j+1],mp(i,j+1)));
            }
        }
        if(j-1>=0)
        {
            int temp=v[i][j-1];
            if(dp[i][j-1]>dp[i][j]+temp)
            {
                dp[i][j-1]=dp[i][j]+temp;
                pq.push(mp(dp[i][j-1],mp(i,j-1)));
            }
        }
        
        
    }
    
    
    
}



int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int **v=new int*[n];
        for(int i=0;i<n;i++)
        {
            v[i]=new int[n];
            for(int j=0;j<n;j++)
            {
                cin>>v[i][j];
            }
        }
        
        int **dp=new int*[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[n];
            for(int j=0;j<n;j++)
            {
                dp[i][j]=INT_MAX;
            }
        }
        dp[0][0]=v[0][0];
        bfs(v,dp,n);
        cout<<dp[n-1][n-1]<<endl;
        
    }
}
