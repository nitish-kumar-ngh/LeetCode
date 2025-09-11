class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>adj;
        
        for(int i=0;i<edges.size();i++){
            int u= edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});

        }
        vector<double>dist(n,-1e8);
        queue<pair<double,int>>q;
        q.push({1,start_node});
        dist[start_node]=0;
        while(q.size()>0){
            double d=q.front().first;
            int node = q.front().second;
            q.pop();
            for(auto v:adj[node]){
                if(dist[v.first]<d*v.second){
                    dist[v.first]=d*v.second;
                    q.push({dist[v.first],v.first});
                }
            }
        }
        return dist[ end_node]==-1e8?0:dist[ end_node];
        

    }
};