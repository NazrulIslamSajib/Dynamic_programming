/*
https://atcoder.jp/contests/dp/tasks/dp_o 
inside ret=0 eta pottker stater er jonno kaj korteche not signle state er jonno


*/
#include<bits/stdc++.h>
using namespace std;
long long n;
long long arr[25][25];
const int mx=(1LL<<21)+123;
long long dp[23][mx];
const int mod=1e9+7;
long long solve(int i,int mask)
{
    if(i>=n)
    {
        return ((1LL<<n)-1)==mask;
    }
    if(dp[i][mask]!=-1)
    {
        return dp[i][mask];
    }
    long long ret=0;
    for(int j=0;j<n;j++)
    {
        if(((1LL<<j) & mask)==0 && arr[i][j]==1)
        {
           ret=ret+solve(i+1,(1LL<<j)|mask);
        }

    }
    return dp[i][mask]=ret%mod;

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
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               cin>>arr[i][j];
           }
       }
       cout<<solve(0,0)<<endl;
    }
    return 0;
}


