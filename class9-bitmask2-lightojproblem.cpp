/* 
Class 2:   Problem says that tomoar kache shurute ekta gun ache seta diye 1 bar kore kore shoot korte paro . ete tomar enemy tar damage hobe 1 decrase kore kore. Tumi jodi kawke ektbar mero gelo felo tahole tar gun use korte paro . tokhon tar proti shoot e koto kore damage hbe seta 2D array er modde deoya ache. 
Amake bolte hbe minimum koto shoot e sob enemy ke shesh korte hbe. .  
https://lightoj.com/problem/agent-47

2D array ta bole I tomo row er ememy jodi mara jay jth column er enemy ke marte hle amar arr[i][j] er
Damage ta nite parbo . that’s it
*/

#include<bits/stdc++.h>
using namespace std;
long long health[15];
long long arr[15][15],n;
const int mx=(1LL<<15)+123;
long long dp[mx];
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
            long long dem=1;
            for(int j=0;j<n;j++)
            {
                if(((1LL<<j) & mask)!=0)
                {
                    dem=max(dem,arr[j][i]);
                }
            }
            long long shoot=(health[i]+dem-1)/dem;
            ret=min(ret,shoot+solve((1LL<<i) | mask));
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
           cin>>health[i];
       }
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               char c;
               cin>>c;
               arr[i][j]=c-'0';
           }
       }
       cout<<"Case "<<tc<<": "<<solve(0)<<endl;

    }
    return 0;
}

