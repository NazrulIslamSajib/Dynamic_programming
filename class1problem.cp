/* 
 https://atcoder.jp/contests/dp/tasks/dp_a
*/
#include<bits/stdc++.h>
using namespace std;
int const mx=1e5+10;
long long arr[mx];
long long dp[mx],n;
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
    long long ret1=INT_MAX,ret2=INT_MAX;
    if(i+1<=n)
    {
        ret1=abs(arr[i+1]-arr[i])+solve(i+1);
    }
    if(i+2<=n)
    {
       ret2=abs(arr[i+2]-arr[i])+solve(i+2);
    }
    dp[i]=min(ret1,ret2);
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
        cin>>n;
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

