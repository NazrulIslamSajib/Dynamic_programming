/*
problem link arek ta: https://vjudge.net/problem/UVA-10616 
ekhane bolche tomake n ta number theke m ta element nite hbe and seta jen d dara divisible hoy, ei types er koto way te choose kora jay seta

*/

#include<bits/stdc++.h>
using namespace std;
long long n,q;
long long dp[210][22][12];
long long arr[230],d,m;
long long solve(long long i,long long j,long long cnt)
{
    if(i>n || cnt>=m)
    {
        return (j==0 && cnt==m);
    }
    if(dp[i][j][cnt]!=-1)
    {
        return dp[i][j][cnt];
    }
    long long ret=0;
    long long d1=(arr[i]+j)%d;
    if(d1<0)
    {
        d1=d1+d;
    }
    ret=ret+solve(i+1,d1,cnt+1);
    ret=ret+solve(i+1,j,cnt);
    return dp[i][j][cnt]=ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=0;
    //cin>>tt;
    while(cin>>n>>q)
    {
        tt++;
        if(n==0 && q==0)
        {
            break;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        cout<<"SET "<<tt<<":"<<endl;
        for(int l=1;l<=q;l++)
        {
            memset(dp,-1,sizeof(dp));
            cin>>d>>m;
            cout<<"QUERY "<<l<<": "<<solve(1,0,0)<<endl;

        }
    }
    return 0;
}
