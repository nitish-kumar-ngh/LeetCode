class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // jai shree Ram
        // graph banao n pliss
        unordered_map<int,vector<pair<int,int>> >adj;
        for(auto vec:times){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            adj[u].push_back({v,wt});
        }
        vector<int>result(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        pq.push({0,k});//wt node
        result[k]=0;
        while(pq.size()>0){
            auto ele=pq.top();
            int node=ele.second;
            int dist=ele.first;
            pq.pop();
            //neighbour pe jayenge
            for(auto v:adj[node]){
                int adjNode=v.first;
                int adjwt=v.second;
                if (dist+adjwt<result[adjNode]){
                    result[adjNode]=dist+adjwt;
                    pq.push({adjwt+dist,adjNode});
                }
            }
        }
        int ans=INT_MIN;
        for (int i=1;i<=n;i++){
            ans=max(result[i],ans);
        }
       return ans==INT_MAX?-1:ans;
        
    }
};