/* 
7/11/2024:  cses DP problem : 
Ekahen tomake coin deoya thakbe tumi segula ki diye koto vabe sum banate paro seta.  
Ekta jinish bujlam tumi return age kono kinchu nite hole seta age diye niye niba.  
/* https://cses.fi/problemset/task/1745/*/

*/
#include<bits/stdc++.h>
using namespace std;
long long arr[105],sum=0,n;
set<long long>st;
const int mx=1e5+123;
long long dp[105][mx];
long long solve(int i,long long curW)
{
    if(i==n+1)
    {
        st.insert(curW);
    }
    if(i>n)
    {
        return 0;
    }
    if(dp[i][curW]!=-1)
    {
     return dp[i][curW];
    }
    long long ret1=0,ret2=0;
    if(arr[i]+curW<=sum)
    {
       solve(i+1,curW+arr[i]);
    }
    solve(i+1,curW);
    return dp[i][curW]=curW;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    //cin>>tt;
    while(tt--)
    {
       cin>>n;
       memset(dp,-1,sizeof(dp));
       for(int i=1;i<=n;i++)
       {
           cin>>arr[i];
           sum+=arr[i];
       }
       solve(1,0);
       cout<<st.size()-1<<endl;
       for(auto x:st)
       {
           if(x!=0)
           {
               cout<<x<<" ";
           }
       }
       cout<<endl;


    }
    return 0;
}

