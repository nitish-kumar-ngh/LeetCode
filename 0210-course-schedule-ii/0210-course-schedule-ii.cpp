class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //graph banao
        int n=numCourses;
        unordered_map<int,vector<int> >adj;
        for (int i=0;i<prerequisites.size();i++){
            int u= prerequisites[i][1];
            int v= prerequisites[i][0];
            adj[u].push_back(v);

        }
        //indegree bnao
        vector<int>indegree(n,0);
        for (int u=0;u<n;u++){
            for (auto v:adj[u]){
                indegree[v]++;
            }
        }
        int cnt=0;
        queue<int>que;
        for (int i=0;i<n;i++){
            if (indegree[i]==0){
                que.push(i);
                cnt++;}
        }
        vector<int>result;
        //simple bfs
        while (que.size()>0){
            int u= que.front();
            que.pop();
            result.push_back(u);
            for (auto v:adj[u]){
                indegree[v]--;
                if (indegree[v]==0){
                    que.push(v);
                    cnt++;
                }
            }
        }
        if (cnt==n)return result;
        else return {};
        
    }
};