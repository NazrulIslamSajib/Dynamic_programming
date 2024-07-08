/*

ekahne 3 ta types ache edit kora
1. replace
2. insert
3. delete 

replace korle problem string i, 2nd string j milbe tai solvce(i+1,j+1) 
insert korle i same thake karon i er age dukacche tai solve(i,j+1)
delete korle j same thakbe tokhon i barbe solve(i+1,j) 

pottek ta operation er man 1 kore, min ta value ber korte hbe.  
https://cses.fi/problemset/task/1639/


*/
#include<bits/stdc++.h>
using namespace std;
const int mx=5e3+123;
int dp[mx][mx];
string s1,s2;
int n1,n2;
long long solve(int i,int j)
{
    if(i>=n1)
    {
        return n2-j;
    }
    if(j>=n2)
    {
        return n1-i;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ret=0;
    if(s1[i]==s2[j])
    {
        ret=solve(i+1,j+1);
    }
    else
    {
        int ret1=1+solve(i+1,j+1);
        int ret2=1+solve(i,j+1);
        int ret3=1+solve(i+1,j);
        ret=min({ret1,ret2,ret3});
    }
   return dp[i][j]=ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
      cin>>s1>>s2;
      n1=s1.size();
      n2=s2.size();
      memset(dp,-1,sizeof(dp));
      cout<<solve(0,0)<<endl;
    }
    return 0;
}


