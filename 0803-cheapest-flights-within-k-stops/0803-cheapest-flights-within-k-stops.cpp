class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i =0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            mp[u].push_back({v,wt});
        }
       int ans = INT_MAX;
       vector<int>vis(n,0);
        queue<pair<int,pair<int,int>>>q;
        q.push({src,{0,0}});
        vis[src]=1;
        vector<int>dist(n,INT_MAX);
        while(q.size()>0){
            int node = q.front().first;
            int x = q.front().second.first;
            int weight = q.front().second.second;
            q.pop();
            if(x<=k+1 && node == dst){
                ans = min(ans,weight);
            }
            for(auto &adjnode:mp[node]){
                if( weight+adjnode.second<dist[adjnode.first]){
                     dist[adjnode.first]=weight+adjnode.second;
                    q.push({adjnode.first,{x+1,weight+adjnode.second}});
                    
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};