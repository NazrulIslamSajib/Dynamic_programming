/*

https://leetcode.com/problems/min-cost-to-connect-all-points/description/  
weight sort kore felte hbe shurute then etar upore disjoint set use korbo. 

*/

class Solution {
public:  
    vector<int>par;   
    vector<int>sz;
    int find_par(int u)
    {
       if(par[u]==u)
       {
        return par[u];
       } 
       return par[u]=find_par(par[u]);
    } 
    void uni(int u,int v)
    {
        if(sz[u]<sz[v]) swap(u,v); 
        par[v]=u;
        sz[u]+=sz[v];
    }
    int count_w(vector<int>&p1,vector<int>&p2) 
    {
        int dis=abs(p1[0]-p2[0])+abs(p1[1]-p2[1]);
        return dis;
    }
    int minCostConnectPoints(vector<vector<int>>& p) { 
        
     int n=p.size();
     vector<pair<int,pair<int,int>>>edges;
     for(int i=0;i<n;i++)
     {
        for(int j=i+1;j<n;j++)
        {   
            int w=count_w(p[i],p[j]);  
            edges.push_back({w,{i,j}});
        }
     }  
     for(int i=0;i<n;i++)
     {
        par.push_back(i);  
        sz.push_back(1);
     } 
     sort(edges.begin(),edges.end()); 
     int ans=0;
     int cnt=0;
     for(int i=0;i<edges.size();i++)
     {  
        int w=edges[i].first;
        int u=edges[i].second.first;
        int v=edges[i].second.second;
        int x=find_par(u); 
        int y=find_par(v);  
        if(x!=y)
        {   
            uni(x,y); 
            ans+=w; 
            cnt++;
            if(cnt==n-1)
            {
                break;
            }
        }
     } 
     return ans;


    }
};
