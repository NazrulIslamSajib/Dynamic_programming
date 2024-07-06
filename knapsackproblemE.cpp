/* 
Ekhane constraints vinno tai 
Ar waight niye kaj na kore korchi value niye ar return korbe waight , minimum waight return korbe. 
https://atcoder.jp/contests/dp/tasks/dp_e

*/
#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+123;
long long dp[105][mx];
long long w[105],v[105],n;
long long solve(int i, int v_left)
{
   if(v_left==0)
   {
       return 0;
   }
   if(i>n)
   {
       return 1e15;
   }
   if(dp[i][v_left]!=-1)
   {
       return dp[i][v_left];
   }
   long long ans=solve(i+1,v_left);
   if(v_left-v[i]>=0)
   {
       ans=min(ans,w[i]+solve(i+1,v_left-v[i]));
   }
   return dp[i][v_left]=ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    //cin>>tt;
    while(tt--)
    {
       long long wmax;
       cin>>n>>wmax;
       memset(dp,-1,sizeof(dp));
       for(int i=1;i<=n;i++)
       {
           cin>>w[i]>>v[i];
       }
       int ok=1e5+123;
       for(int i=ok;i>=0;i--)
       {
           if(solve(1,i)<=wmax)
           {
               cout<<i<<endl;
               break;
           }
       }
    }
    return 0;
}
