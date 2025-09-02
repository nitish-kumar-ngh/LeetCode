class Solution {
public:
bool dfs(  unordered_map<int,vector<int>>&adj,int node,vector<int>&vis, vector<int>&pathvis){
        vis[node]=1;
        pathvis[node]=1;
        
        for(auto &it:adj[node]){
            if(vis[it]==0){
                if(dfs(adj,it,vis,pathvis))return true;
            }else if(pathvis[it])return true;
        }
         pathvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
         
        unordered_map<int,vector<int>>adj;
        
        for(int i=0;i<V;i++){
           for(  auto &it:graph[i]){
            adj[i].push_back(it);
           }
        }
        
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(adj,i,vis,pathvis);
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(pathvis[i]==0)ans.push_back(i);
        }
        return ans;
    }
};