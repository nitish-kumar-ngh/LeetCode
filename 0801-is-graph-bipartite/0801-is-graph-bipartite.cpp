class Solution {
public:
    bool bfs(int node, unordered_map<int,vector<int>>&adj,vector<int>&color){
        queue<int>q;
        q.push(node);
        color[node]=0;
        while(q.size()>0){
            int x = q.front();
            q.pop();
            for(auto adjnode:adj[x]){
                if(color[adjnode]==-1){
                   q.push(adjnode);
                   color[adjnode]=!color[x];
                }else if(color[adjnode]==color[x])return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
         int n = graph.size();
      //   int m = graph[0].size();
        unordered_map<int,vector<int>>adj;

        for(int i = 0;i<n;i++){
            for(int j =0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int>color(n,-1);
        for(int i =0;i<n;i++){
            if(color[i]==-1){
                if(bfs(i,adj,color)==false)return false;
            }
        }
        return true;
    }
};