class Solution {
public: 
    vector<int>par;  
    int find_par(int u)
    {
        if(par[u]==u) return u; 
        return find_par(par[u]);
    }
    void uni(int u,int v)
    {
        par[v]=u;
    } 
    int findCircleNum(vector<vector<int>>& g) { 
     int n=g.size();
     for(int i=0;i<n;i++)
     {
        par.push_back(i);
     }
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<n;j++)
        {
            if(g[i][j])
            {
                int u=find_par(i);
                int v=find_par(j);
                if(u!=v)
                {
                    uni(u,v);
                }
            }
        }
     }  
     int ans=0;
     for(int i=0;i<n;i++)
     {
        if(par[i]==i)
        {
            ans++;
        }
     } 
     return ans;

        
    }
};
