class Solution {
public:
  

    void dfs(int node, unordered_map<int,vector<int>>&adj, vector<int>&vis) {
        vis[node]=1;
       // c=max(c,cnt);
        for(auto v:adj[node]) {
            if(vis[v]==0) {
                dfs(v,adj,vis);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<bombs.size();i++) {
            for(int j=0;j<bombs.size();j++) {
                if(i==j) continue;
                int x1=bombs[i][0];
                int y1=bombs[i][1];
                int x2=bombs[j][0];
                int y2=bombs[j][1];
                long long d=(long long)(x1-x2)*(x1-x2)+(long long)(y1-y2)*(y1-y2);
                double dist=sqrt(d);
                if(dist<=(bombs[i][2])){ adj[i].push_back(j);  }
            }
        }
        int n=bombs.size();
        int ans=0;
          
        for(int i=0;i<n;i++) {
            vector<int> vis(n,0);
       
            dfs(i,adj,vis);
            int c =0;
            for(int i=0;i<n;i++){
                if(vis[i]==1)c++;
            }
            ans=max(ans,c);
          }
          
        
        return ans;
    }
};
