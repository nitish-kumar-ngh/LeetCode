class Solution {
public:
void bfs(int u,vector<int>adj[],vector<int>&vis){
    queue<int>q;
    q.push(u);
    vis[u]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto v:adj[node]){
            if (!vis[v]){
                q.push(v);
                vis[v]=1;
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int noOfvertex=isConnected.size();
        vector<int>adj[noOfvertex+1];
        for (int i=0;i<isConnected.size();i++){
            for (int j=0;j<isConnected[0].size();j++){
                if (isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        for (auto v:adj[1]){
             cout<<v<<" ";
        }
        int cnt=0;
        vector<int>vis(noOfvertex+1,0);
        for (int i=1;i<=noOfvertex;i++){
            if (!vis[i]){
                cnt++;
                bfs(i,adj,vis);
            }
        }
        return cnt;
    }
};