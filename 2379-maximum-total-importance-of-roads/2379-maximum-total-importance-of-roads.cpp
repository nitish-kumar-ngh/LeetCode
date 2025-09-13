class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<int>>adj;
        vector<int>in(n,0);
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            in[u]++;
            in[v]++;
        }
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            int node = i;
            int value = in[i];
            p.push_back({value,node});
        }
        sort(p.begin(),p.end());
        int cnt =1;
        vector<int>val(n,0);
        for(int i =0;i<p.size();i++){
            int node = p[i].second;
            val[node]=cnt;
            cnt++;
        }
        long long ans =0;
          for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            ans+=(val[u]+val[v]);
        }
        return ans;
    }
};