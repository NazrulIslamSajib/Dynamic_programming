/*
https://cses.fi/problemset/task/1633
*/
#include<bits/stdc++.h>
using namespace std;
long long n;
const int mx=1e6+123;
int dp[mx];
int mod=1e9+7;
long long solve(int i)
{
    if(i==n)
    {
        return 1;
    }
    if(i>n)
    {
        return 0;
    }
    if(dp[i]!=-1)
        return dp[i];
    }
    long long ret=0;
    for(int k=1;k<=6;k++)
    {
        ret=ret+solve(i+k);
    }
    return dp[i]=ret%mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    while(tt--)
    {
       cin>>n;
       memset(dp,-1,sizeof(dp));
       cout<<solve(0)<<endl;
    }
    return 0;
}


