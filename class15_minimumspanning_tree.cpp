#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt;
    cin>>tt;
    while(tt--)
    {
        long long n,i,j;
        cin>>n;
        char arr[3][n+10];
        set<char>st;
        for(i=1;i<=2;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>arr[i][j];
                st.insert(arr[i][j]);
            }
        }
        if(st.size()==1)
        {
            cout<<0<<endl;
        }
        else
        {
            long long cnt1=0,cnt2=0;
            for(i=1;i<=2;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if((j-1)>=1 && (j+1)<=n && arr[i][j]=='.' && arr[i][j-1]=='.' && arr[i][j+1]=='.' && arr[i+1][j-1]=='x' && arr[i+1][j+1]=='x' && arr[i+1][j]=='.')
                    {
                        cnt1++;
                    }
                }
                break;
            }
            for(i=2;i<=2;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if((j-1)>=1 && (j+1)<=n && arr[i][j]=='.' && arr[i][j-1]=='.' && arr[i][j+1]=='.' && arr[i-1][j+1]=='x' && arr[i-1][j-1]=='x' && arr[i-1][j]=='.')
                    {
                        cnt2++;
                    }
                }
                break;
            }
            cout<<cnt1+cnt2<<endl;
        }
    }
    return 0;
}

