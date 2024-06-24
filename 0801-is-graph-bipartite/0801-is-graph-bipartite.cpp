class Solution {
public:
bool checkBipartiteBFS(int curr,vector<vector<int>>& adj, vector<int>&color,int currColor){
      queue<int>que;
      color[curr]=currColor;
      que.push(curr);
      while (que.size()>0){
        int u=que.front();
        que.pop();
         for (auto v:adj[u]){
        if (color[v]==color[u])return false;
        if (color[v]==-1){
            color[v]=1-color[u];
            que.push(v);
        }
      }
      }

    

        return true;

}
    bool isBipartite(vector<vector<int>>& adj) {
        int V= adj.size();
        vector<int>color(V,-1);//abhi koi color nahi huwa hai 
        for (int i=0;i<V;i++){
            if (color[i]==-1){
                if (checkBipartiteBFS(i,adj,color,1)==false) return false;
            }
        }
       return true; 
    }
};