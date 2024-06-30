class Solution {
public:

    void BFS(int u,unordered_map<int,vector<int> >&mp, vector<bool>&visited){
            
            queue<int>que;
            que.push(u);
            visited[u]=true;
            while (que.size()>0){
                int u= que.front();
                que.pop();
                for (int v:mp[u]){
                    if (!visited[v]){
                        que.push(v);
                        visited[v]=true;
                    }
                }
            }



    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //graph banao
        int V = edges.size();
        if (V==0)return true;
        unordered_map<int,vector<int> >mp;
        for (auto edge:edges){
            int x= edge[0];
            int y= edge[1];
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        
        vector<bool>visited(n,false);

       BFS(source,mp,visited);

       if (visited[destination]==false)return false;
       else return true;
        


    }
};