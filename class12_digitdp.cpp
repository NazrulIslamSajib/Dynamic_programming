/*
problem statement says that
tomake l,r dibo tumi l-r pojjon koyta number k dara divisible and eder digit sum gula o k dara divisible hbe.

to ami  shurute 1 theke r pojjonto ta ver korchi
then l-1 er jonno ber korchi then sheshe 2 ta biyog kore dichi.
 
https://lightoj.com/problem/investigation

*/

#include<bits/stdc++.h>
using namespace std;
long long l,r,k;
vector<long long>v1,v2;
long long dp[10][100][100][3];
long long dp1[10][100][100][3];
long long solve1(int i,int m1,int m2,int f)
{
    if(i>=v1.size())
    {
        return (m1==0 && m2==0);
    }
    if(dp[i][m1][m2][f]!=-1)
    {
        return dp[i][m1][m2][f];
    }
    long long ret=0;
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
         ret+=solve1(i+1,((m1*10)+j)%k,(m2+j)%k,( f || j<v1[i]));/// f==1 or j<v[i] ekta sotto hole f==1 hoye jabe
    }
    return dp[i][m1][m2][f]=ret;
}
long long solve2(int i,int m1,int m2,int f)
{
    if(i>=v2.size())
    {
        return (m1==0 && m2==0);
    }
    if(dp1[i][m1][m2][f]!=-1)
    {
        return dp1[i][m1][m2][f];
    }
    long long ret=0;
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
    {
        ret+=solve2(i+1,((m1*10)+j)%k,(m2+j)%k,( f || j<v2[i]));
    }
    return dp1[i][m1][m2][f]=ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt;
    cin>>tt;
    for(int tc=1;tc<=tt;tc++)
    {
      v1.clear();
      v2.clear();
      cin>>l>>r>>k;
      memset(dp,-1,sizeof(dp));
      memset(dp1,-1,sizeof(dp1));
      if(k<=90)
      {
        long long rr=r,ll=l;
        while(rr)
        {

            long long num=rr%10;
            v1.push_back(num);
            rr=rr/10;
        }
        reverse(v1.begin(),v1.end());
        ll--;
        if(ll==0)
        {
            v2.push_back(0);
        }
        while(ll)
        {
            long long num=ll%10;
            v2.push_back(num);
            ll=ll/10;
        }
        reverse(v2.begin(),v2.end());
        long long cnt1=solve1(0,0,0,0);
        long long cnt2=solve2(0,0,0,0);
        cout<<"Case "<<tc<<": "<<cnt1-cnt2<<endl;

      }
      else
      {
           cout<<"Case "<<tc<<": "<<0<<endl;
      }
    }
    return 0;
}


