class Solution {
public:
     vector<vector<int>>ans;
    void f(int node, vector<int>vis,  unordered_map<int,vector<int>>&adj, vector<int>&temp,int n){

        vis[node]=1;
        temp.push_back(node);
        if(node== n-1){
            ans.push_back(temp);
        }
        for(auto & adjnode:adj[node]){
            if(vis[adjnode]==0){
                 f(adjnode,vis,adj,temp,n);
            }
        }
        temp.pop_back();
    
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>adj;
        int n = graph.size();
        for(int i=0;i<n;i++){
            for(int x:graph[i]){
                adj[i].push_back(x);
            }
        }
        vector<int>vis(n,0);
        vector<int>temp;
        f(0,vis,adj,temp,n);
        return ans;
    }
};