class Solution {
public:
 int t[200003];
    typedef pair<long long ,long long >p;
    int mod = 1000000007;
    int f(vector<long long >&dist,int src,int end, unordered_map<int,vector<pair<int,int>>>&adj){
        if(src==end)return 1;
        if(t[src]!=-1)return t[src];
        long long ans =0;
        for(auto &nei:adj[src]){
            int neigh = nei.first;
            if(dist[src]>dist[neigh]){
             ans=ans%mod+f(dist,neigh,end,adj)%mod;
            }
        }
        return t[src]=ans%mod;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        memset(t,-1,sizeof(t));
          unordered_map<int,vector<pair<int,int>>>adj;
          for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
          }
          vector<long long >dist(n+1,1e15);
          dist[n]=0;
          priority_queue<p,vector<p>,greater<p>>pq;
          pq.push({0,n});
          while(pq.size()>0){
            auto [d,node]=pq.top();
            pq.pop();
            for(auto &nei:adj[node]){
                if(dist[nei.first]>d+nei.second){
                   dist[nei.first]= d+nei.second;
                   pq.push({dist[nei.first],nei.first});
                }
            }
          }
          return f(dist,1,n,adj);
    }
};