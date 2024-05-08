/*
  i,i+1,i+2,i+3,.... i+k pojjonto jodi lap dite pare 
  https://atcoder.jp/contests/dp/tasks/dp_b
*/

#include<bits/stdc++.h>
using namespace std;
int const mx=1e5+10;
long long arr[mx];
long long dp[mx],n,k;
long long solve(long long i)
{
    if(i==n)
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    long long ret=INT_MAX;
    for(int j=1;j<=k;j++)
    {
        if(i+j<=n)
        {
            ret=min(ret,abs(arr[i]-arr[i+j])+solve(i+j));
        }
    }

    dp[i]=ret;
    return dp[i];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt;
   /// cin>>tt;
   tt=1;
    while(tt--)
    {
        cin>>n>>k;
        long long i;
        memset(dp,-1,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        cout<<solve(1)<<endl;
    }
    return 0;
}

