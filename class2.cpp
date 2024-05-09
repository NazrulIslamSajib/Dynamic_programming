/* 
 link : https://atcoder.jp/contests/dp/tasks/dp_c
*/ 
#include<bits/stdc++.h>
using namespace std;
int const mx=1e5+10;
int dp[mx][4];
int arr[mx][4],n;
int solve(int i,int f)
{
    if(i>n)
    {
        return 0;  /// ekhane n er beshi hole zero hoye jabe as usual .
    }
    if(dp[i][f]!=-1)
    {
        return dp[i][f];
    }
    int ret=0;   ///reting marks
    for(int j=1;j<=3;j++)
    {
        if(j!=f)  /// ami je samne jabo seta jeno previous er sathe na mile se jonno j!=f   f hocche previous
        {
            ret=max(ret,arr[i][j]+solve(i+1,j));  /// mai currenct er man ber kortechi then 2nd jacchi  and j th ta kaj korbo se i tomo dine
        }
    }
    return dp[i][f]=ret;
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
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
        }
        memset(dp,-1,sizeof(dp));
        cout<<solve(1,0)<<endl;
    }
    return 0;
}

