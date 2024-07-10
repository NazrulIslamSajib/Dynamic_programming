/*https://cses.fi/problemset/task/1637/
*/ 
#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+123;
int dp[mx];
long long min1=INT_MAX;
long long solve(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    long long x=n;
    long long ret=INT_MAX;
    vector<long long>v;
    while(x)
    {
      long long digit=x%10;
      x=x/10;
      if(digit>0)
      {
          v.push_back(digit);
      }
    }
    for(auto x:v)
    {
      ret=min(ret,1+solve(n-x));
    }
    return dp[n]=ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    //cin>>tt;
    while(tt--)
    {
       long long n;
       cin>>n;
       memset(dp,-1,sizeof(dp));
       cout<<solve(n)<<endl;
    }
    return 0;
}

