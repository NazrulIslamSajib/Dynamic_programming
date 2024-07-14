/* 
Class 4:   mask er somoy jeta neoya hoye geche seta 1 diye check kore na seta not equal diye check kore re pagla 
If((i<<j) & mask!=0)  ei vabe 

Ei class er problem ami solve korechi .. 
https://lightoj.com/problem/pimp-my-ride 
problem statement:   
koyek ta garage ache akta market e , tumi sei garage gula te tomar gari thik korte paro, tumi 
i tom garage thik korte jodi jao tahole tumi arr[i][j] cost dite hbe must, arek ta ache tumi jodi er previous gula te visit koro tahole o kichu sonhkok pain dite hbe . 
minimum koto koste tumi sob visit korte paro.
*/
#include<bits/stdc++.h>
using namespace std;
int arr[20][20];
const int mx=(1LL<<14)+123;
long long dp[mx],n;
long long solve(long long mask)
{
    if(((1LL<<n)-1)==mask)
    {
        return 0;
    }
    if(dp[mask]!=-1)
    {
        return dp[mask];
    }
    long long ret=INT_MAX;
    for(int i=0;i<n;i++)
    {
       if(((1LL<<i) & mask)==0)
       {
          long long cur=arr[i][i];
          for(int j=0;j<n;j++)
          {
            if(((1LL<<j) & mask)!=0)
            cur=cur+arr[i][j];
          }
           ret=min(ret,cur+solve((1LL<<i) | mask));
       }
    }
    return dp[mask]=ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt;
    cin>>tt;
    for(int tc=1;tc<=tt;tc++)
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
       cout<<"Case "<<tc<<": "<<solve(0)<<endl;

    }
    return 0;
}


