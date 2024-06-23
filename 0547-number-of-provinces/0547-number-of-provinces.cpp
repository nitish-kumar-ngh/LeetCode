class Solution {
public:
int n;
void dfs (int u,vector<vector<int>>& isConnected,vector<bool>&visited){
    if (visited[u]==true) return;
    visited[u]=true;
    for (int v=0;v<n;v++){
        if (!visited[v]&&isConnected[v][u]==1){
            dfs(v,isConnected,visited);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
         n= isConnected.size();
        vector<bool>visited(n,false);
        int cnt=0;
        for (int i=0;i<n;i++){
            if (!visited[i]){
                dfs(i,isConnected,visited);
                cnt++;
            }
        }
        return cnt;
    }
};