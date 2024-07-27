class Solution {
public:
    typedef pair<int,int>P;
    void dikstra(vector<vector<int>>&result,unordered_map<int,vector<pair<int,int> >>&adj,int src){
        priority_queue<P,vector<P>,greater<P>>pq;
        result[src][src]=0;
        pq.push({0,src});
        while(pq.size()>0){
            auto ele=pq.top();
            pq.pop();
            int dist=ele.first;
            int node=ele.second;
            for(auto v:adj[node]){
                int d=v.second;
                int adjnode=v.first;
                if (d+dist<result[src][adjnode]){
                    result[src][adjnode]=d+dist;
                    pq.push({d+dist,adjnode});
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int> >>adj;
        for (auto vec:edges){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<vector<int>>result(n,vector<int>(n,INT_MAX));
        for (int src=0;src<n;src++){
            dikstra(result,adj,src);
        }
        int cnt=0;
        int ans=INT_MAX;
        for (int i=0;i<n;i++){
            cnt=0;
            for (int j=0;j<n;j++){
                if (result[i][j]<= distanceThreshold || result[i][j]==INT_MAX)cnt++;
            }
             ans=min(ans,cnt);
            

        }
        cout<<ans<<"\n";
        int r=-1;
          
           for (int i=0;i<n;i++){ 
            for (int j=0;j<n;j++){
             cout<<result[i][j]<<" ";
            }
            cout<<"\n";
           }
            

        
        for (int i=0;i<n;i++){
            cnt=0;
            for (int j=0;j<n;j++){
              if (result[i][j]<= distanceThreshold || result[i][j]==INT_MAX)cnt++;
            }
            if (ans==cnt)r=i;
            

        }
        

        return r;
    }
};