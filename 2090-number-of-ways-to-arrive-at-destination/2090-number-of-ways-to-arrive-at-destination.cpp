class Solution {
public:
  int ans =0;
   
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dist(n,1e15);
        vector<long long> ways(n,0);
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto &r:roads){
            int u=r[0], v=r[1], wt=r[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        int mod = 1e9+7;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});

        while(!pq.empty()){
            auto [d,node] = pq.top();
            pq.pop();

           // if(d>dist[node]) continue;

            for(auto &v:adj[node]){
                int nei=v.first, wt=v.second;
                if(dist[nei]>d+wt){
                    dist[nei]=d+wt;
                    ways[nei]=ways[node];   // reset count
                    pq.push({dist[nei],nei});
                }else if(dist[nei]==d+wt){
                    ways[nei]=(ways[nei]+ways[node])%mod;  // accumulate paths
                }
            }
        }
        return ways[n-1]%mod;
    }
};

