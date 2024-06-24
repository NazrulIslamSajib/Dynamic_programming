/*

  Link: 357 - Let Me Count The Ways uva problem
  https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2078
  statemenet: Problem: amar kache 21 coin generate korte hbe jeta cubic coin ache ami seta gula use kore koto vabe n generate korte parbo setar problem
  coin changing problem .

*/
#include<bits/stdc++.h>
using namespace std;
int const mx=1e4+123;
long long dp[22][mx];
long long v[23];
void gen(long long n)
{
    for(int i=1;i<=n;i++)
    {
        v[i-1]=i*i*i;
    }
}
long long solve(long long i,long long n)
{
    if(i==21 || n==0)
    {
        return n==0;
    }
    if(dp[i][n]!=-1)
    {
        return dp[i][n];
    }
    long long ret=0;
    for(int j=0;j<=n;j++)
    {
        if((n-(j*v[i]))>=0)
        {
            ret+=solve(i+1,n-(j*v[i]));
        }
        else break;
    }
    return dp[i][n]=ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    gen(21);
    long long n;
    memset(dp,-1,sizeof(dp));
    while(cin>>n)
    {
       cout<<solve(0,n)<<endl;

    }
    return 0;
}
