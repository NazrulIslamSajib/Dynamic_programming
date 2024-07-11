/*
Dhoro Tomoke bolche ith bit ta 1 raho tahole . ami ki korbo OR 
Mask | ((1<<i)) 
https://lightoj.com/problem/marriage-ceremonies 

problem statement ta hocche amake row borabor chele thakbe ar column borabor meye thakbe amake emon vabe biye dite hbe jen value maximum hoy. 
To ami mask namk nilam seta setar sathe kon kon meyer biye hoiche ki hoy nai seta check kortechi. 

*/

#include<bits/stdc++.h>
using namespace std;
long long n;
long long arr[20][20];
const int mx=(1LL<<16)+123;
long long dp[20][mx];
long long solve(int i,long long  mask)
{
    if(i>=n)
    {
        return 0;
    }
    if(((1LL<<n)-1)==mask)
    {
        return 0;
    }
    if(dp[i][mask]!=-1)
    {
        return dp[i][mask];
    }
    long long ret=0;
    for(long long j=0;j<n;j++)
    {
        if(((1LL<<j) & mask)==0)
        {
            ret=max(ret,arr[i][j]+solve(i+1, ((1LL<<j) | mask)));
        }
    }
    return dp[i][mask]=ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    cin>>tt;
    for(int tc=1;tc<=tt;tc++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<tc<<": "<<solve(0,0)<<endl;
    }
    return 0;
}

