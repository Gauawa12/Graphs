Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which total cost incurred is minimum.

Note : It is assumed that negative cost cycles do not exist in input matrix.

Input:
The first line of input will contain number of testcases T. Then T test cases follow. Each test case contains 2 lines. The first line of each test case contains an integer N denoting the size of the grid. Next line of each test contains a single line containing N*N space separated integers depecting cost of respective cell from (0,0) to (N,N).

Output:
For each test case output a single integer depecting the minimum cost to reach the destination.

Constraints:
1 <= T <= 50
1 <= N <= 50

Example:
Input:
2
5
31 100 65 12 18 10 13 47 157 6 100 113 174 11 33 88 124 41 20 140 99 32 111 41 20
2
42 93 7 14

Output:
327
63

Explanation:
Testcase 1:
Grid is:
31, 100, 65, 12, 18,
10, 13, 47, 157, 6,
100. 113, 174, 11, 33,
88, 124, 41, 20, 140,
99, 32, 111, 41, 20
A cost grid is given in below diagram, minimum
cost to reach bottom right from top left
is 327 (31 + 10 + 13 + 47 + 65 + 12 + 18 + 6 + 33 + 11 + 20 + 41 + 20)




Solution:

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
