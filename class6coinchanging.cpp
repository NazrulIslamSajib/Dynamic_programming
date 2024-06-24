/*

  Link: 357 - Let Me Count The Ways uva problem
  https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=293
  statemenet: Problem: amar kache kichu coin ache ami seta gula use kore koto vabe n generate korte parbo setar problem
  coin changing problem .

*/
#include<bits/stdc++.h>
using namespace std;
long long v[]={1,5,10,25,50};
int const mx=4e4+123;
long long dp[6][mx];
long long solve(long long i,long long n)
{
    if(i==5 || n==0)
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
    long long n;
    memset(dp,-1,sizeof(dp));
    while(cin>>n)
    {
        long long y=solve(0,n);
        if(y==1)
        {
            cout<<"There is only 1 way to produce "<< n<<" cents change."<<endl;
        }
        else
        {
            cout<<"There are "<<y<<" ways to produce "<<n<<" cents change."<<endl;

        }
    }
    return 0;
}
