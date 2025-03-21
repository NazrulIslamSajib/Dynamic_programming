/*
Tumi ekta circle er vitore dariye acho. Tomar tumi circle er poridi te monster ke marte paro por por 3 ta consecutive jon ke tara mara jabe and baki gula tumake hotta korbe . bolte hbe minimum koto health tomar khoroc hbe.  
/* https://acm.timus.ru/problem.aspx?space=1&num=1152 */

#include<bits/stdc++.h>
using namespace std;
long long n;
long long arr[25];
const int mx=(1LL<<20)+123;
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
    long long dmg=0;
    for(int i=0;i<n;i++)
    {
        if(((1LL<<i) & mask)==0)
        {
            dmg+=arr[i];
        }
    }
    long long ret=1e17;
    for(int i=0;i<n;i++)
    {
        if(((1LL<<i)& mask)==0)
        {
            long long id1=i;
            long long id2=(i+1)%n;
            long long id3=(i+2)%n;
            long long tdmg=dmg;
            if(((1LL<<id1) & mask)==0)
            {
                tdmg=tdmg-arr[id1];
            }
            if(((1LL<<id2) & mask)==0)
            {
                tdmg=tdmg-arr[id2];
            }
            if(((1LL<<id3) & mask)==0)
            {
                tdmg=tdmg-arr[id3];
            }
            long long newmask=mask;
            newmask |=(1<<id1);
            newmask |=(1<<id2);
            newmask |=(1<<id3);
            ret=min(ret,tdmg+solve(newmask));
        }
    }
    return dp[mask]=ret;
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
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
       }
       cout<<solve(0)<<endl;
    }
    return 0;
}

