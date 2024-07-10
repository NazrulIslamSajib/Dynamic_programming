/* 
Class 19:   ekhane bola hoyeche tumi 2 ta string er  emon ekta subsequence niba and baki je element gula niba setar jen ascii value minimum hoy. 
https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
*/



const int mx=1005;
int dp[mx][mx];
string ok1,ok2; 
map<char,long long>mp;
long long solve(int i,int j)
{
    if(i>=ok1.size() || j>=ok2.size())
    {
        return 0;
    } 
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    } 
    long long ret=0;
    if(ok1[i]==ok2[j])
    {
        ret=mp[ok1[i]]+solve(i+1,j+1);
    }  
    else 
    {
        ret=max(solve(i,j+1),solve(i+1,j));
    }  
    return dp[i][j]=ret;
}

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {    
    memset(dp,-1,sizeof(dp));
     for(char i='a';i<='z';i++)
     {
        mp[i]=int(i);
     } 
     for(char i='A';i<='Z';i++)
     {
        mp[i]=int(i);
     } 
     ok1=s1;
     ok2=s2; 
     long long max1=solve(0,0); 
     long long ascii1=0,ascii2=0;
     for(auto x:s1)
     {
        ascii1+=mp[x];
     } 
     for(auto x:s2)
     {
        ascii2+=mp[x];
     }
     return ascii1+ascii2-2*max1;
        
    }
};
