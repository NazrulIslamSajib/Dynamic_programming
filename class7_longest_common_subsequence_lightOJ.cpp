/* 
2nd problem :    problem statement says that tomake 2 ta string deoya hbe , tumi minimum ekta string er size dao seta oi duita string er sub string hbe and ei rokom koyta substring banana jabe seta dao 
https://lightoj.com/problem/love-calculator
*/

#include<bits/stdc++.h>
using namespace std;
string s1,s2;
const int mx=30;
long long dp1[mx][mx];
long long ans1;
long long lcs(int i,int j)
{
    if(i>=s1.size() || j>=s2.size())
    {
        return 0;
    }
    if(dp1[i][j]!=-1)
    {
        return dp1[i][j];
    }
    long long ret=0;
    if(s1[i]==s2[j])
    {
        ret=1+lcs(i+1,j+1);
    }
    else
    {
        ret=max(lcs(i,j+1),lcs(i+1,j));
    }

    return dp1[i][j]=ret;
}
long long dp2[33][33][65];
long long solve(long long i,long long j,long long k)
{
    if(i==s1.size() && j==s2.size())
    {
        return k==ans1;
    }
    else if(k==ans1)
    {
        return 0;
    }
    if(dp2[i][j][k]!=-1)
    {
        return dp2[i][j][k];
    }
    long long ret=0;
    for(char c='A';c<='Z';c++)
    {
        ret+=solve(i+(s1[i]==c),j+(s2[j]==c),k+1);
    }
    return dp2[i][j][k]=ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt;
    cin>>tt;
    for(int tc=1;tc<=tt;tc++)
    {
      cin>>s1>>s2;
      memset(dp1,-1,sizeof(dp1));
      memset(dp2,-1,sizeof(dp2));
      ans1=s1.size()+s2.size()-lcs(0,0);
      long long ans2=solve(0,0,0);
      cout<<"Case "<<tc<<":"<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}

