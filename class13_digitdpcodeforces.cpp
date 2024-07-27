/*
amar kache ekta m,d thakebe and 
dhuta number a and b thakbe 
amake bolte hbe a-b er majkhane koyta number ache
jekhane  protita even position e d thakbe and seta m dara divisible hbe 

https://codeforces.com/contest/628/problem/D

*/
#include<bits/stdc++.h>
using namespace std;
vector<long long>v1,v2;
long long d,k;
const int mx=2050;
long long dp1[mx][mx][3];
long long dp2[mx][mx][3];
const int mod=1e9+7;
long long ans=0;
void cal1(string s1)
{
    for(int i=0;i<s1.size();i++)
    {
        v1.push_back(s1[i]-'0');
    }
}
void cal2(string s2)
{
    for(int i=0;i<s2.size();i++)
    {
        v2.push_back(s2[i]-'0');
    }
}
long long solve1(int i,int m,int f)
{
    if(i>=v1.size())
    {
        return m==0;
    }
    if(dp1[i][m][f]!=-1)
    {
        return dp1[i][m][f];
    }
    long long ret=0;
    if(i%2==1)
    {
        if(f==1 || d<=v1[i])
        {
            ret=solve1(i+1,((m*10)+d)%k,f || (d<v1[i]));
        }
    }
    else
    {
        long long limit;
        if(f==1)
        {
            limit=9;
        }
        else
        {
            limit=v1[i];
        }
        for(int j=0;j<=limit;j++)
        {
            if(j==d) continue;
            ret=(ret%mod+solve1(i+1,((m*10)+j)%k,f || (j<v1[i])))%mod;
        }
    }
    return dp1[i][m][f]=ret;

}
long long solve2(int i,int m,int f)
{
    if(i>=v2.size())
    {
        return m==0;
    }
    if(dp2[i][m][f]!=-1)
    {
        return dp2[i][m][f];
    }
    long long ret=0;
    if(i%2==1)
    {
        if(f==1 || d<=v2[i])
        {
            ret=solve2(i+1,((m*10)+d)%k, f || (d<v2[i]));
        }
    }
    else
    {
        long long limit;
        if(f==1)
        {
            limit=9;
        }
        else
        {
            limit=v2[i];
        }
        for(int j=0;j<=limit;j++)
        {   if(j==d)continue;
            ret=(ret%mod+solve2(i+1,((m*10)+j)%k,f || (j<v2[i]))%mod)%mod;
        }
    }
    return dp2[i][m][f]=ret;

}
void last()
{
    long long mul=0,flag=0;
    for(int i=0;i<v1.size();i++)
    {
        if(i%2==1 && v1[i]!=d)
        {
            flag=1;
            ans=0;
            break;
        }
        else if(v1[i]==d && i%2==0)
        {
           flag=1;
           ans=0;
           break;
        }
        mul=((mul*10)+v1[i])%k;
    }
    if(mul==0 && flag==0)
    {
        ans=1;
    }
    else
    {
        ans=0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
   /// cin>>tt;
    while(tt--)
    {
       memset(dp1,-1,sizeof(dp1));
       memset(dp2,-1,sizeof(dp2));
       cin>>k>>d;
       string s1,s2;
       cin>>s1>>s2;
       cal1(s1);
       cal2(s2);
       long long cnt1=solve1(0,0,0);
       long long cnt2=solve2(0,0,0);
       last();
       long long ok=(cnt2%mod-cnt1%mod+ans%mod)%mod;
       while(ok<0)
       {
           ok=ok+mod;
       }
       cout<<ok<<endl;
    }
    return 0;
}

