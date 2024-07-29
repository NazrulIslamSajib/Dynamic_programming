class Solution {
public: 
    vector<int>par;  
    vector<int>sz; 
    /// path compression  
    int find_par(int u)
    {
        if(par[u]==u) return u; 
        return par[u]=find_par(par[u]);
    } 
    //// union by size jar size choto take boro sub tree er modde rakhte raktechi
    void uni(int u,int v)
    {   
        if(sz[u]<sz[v]) swap(u,v);
        par[v]=u; 
        sz[u]+=sz[v];
    } 

    int findCircleNum(vector<vector<int>>& g) { 
     int n=g.size();
     for(int i=0;i<n;i++)
     {
        par.push_back(i);
        sz.push_back(1);
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
