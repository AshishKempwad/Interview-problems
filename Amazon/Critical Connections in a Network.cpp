class Solution {
public:
    int timer=0;
vector<vector<int>>ans;

void dfs(int node, int par, vector<bool>&vis, vector<int>&id, vector<int>&low_link,vector<vector<int>>&graph)
{
    vis[node]=true;
    id[node] = low_link[node]=timer++;
   
    
    for(auto x : graph[node])
    {
        if(x != par)
        {
            if(!vis[x])
            {
                dfs(x,node,vis,id,low_link,graph);
                low_link[node] = min(low_link[node], low_link[x]);
                if(id[node] < low_link[x])
                {
                    ans.push_back({node,x});
                }
            }
            else
            {
                low_link[node] = min(low_link[node],low_link[x]);
            }
        }
    }
}
     
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
    {
        vector<vector<int>>graph(n+1);
        for(auto &x : connections)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        vector<bool>vis(n+1,false);
        vector<int>id(n+1,0);
        vector<int>low_link(n+1,0);
        
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,i,vis,id,low_link,graph);
            }
        }
        return ans;
    }
};
