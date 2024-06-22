/* 
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3654 
problem ta ei rokom je 
tomake ekta n dibo arek ta k dibo , 
tomake bolte hobe k songkkok prime niye and n sum hoye koto vabe kora jabe seta koro. 
eta hocce question 
*/
#include<bits/stdc++.h>
using namespace std;
bool prime[90000001];
long long max1=1200;
vector<long long>v;
long long n,k;
/// prime counting 1.6(x/ln(x));
long long dp[300][1200][20];
void p()
{
    prime[0]=true;
    prime[1]=true;
    for(int i=2;i*i<=max1;i++)
    {

        if(prime[i]==false)
        {
            for(long long j=i*i;j<=max1;j=j+i)
            {
                prime[j]=true;
            }
        }
    }
    for(int i=2;i<=max1;i++)
    {
        if(prime[i]==false)
        {
            v.push_back(i);
        }
    }
}
long long solve(long long i,long long j,long long cnt)
{
    //cout<<i<<" ";
    if(i==v.size() || j>=n || cnt>=k)
    {
        if(j==n && cnt==k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(dp[i][j][cnt]!=-1)
    {
        return dp[i][j][cnt];
    }
    long long ret=0;
    ret+=solve(i+1,j+v[i],cnt+1);
    ret+=solve(i+1,j,cnt);

    return dp[i][j][cnt]=ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    p();
    while(cin>>n>>k)
    {
        if(n==0 && k==0)
        {
            break;
        }
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,0,0)<<endl;
    }
    return 0;
}
