class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //graph banao
       
        unordered_map<int,vector<int > >adj;
        int row=prerequisites.size();
        if (row==0)return true;
        int col=prerequisites[0].size();
        for (int i=0;i<row;i++ ){
                int u=prerequisites[i][1];
                int v=prerequisites[i][0];
                adj[u].push_back(v);
        }
        //kahns algorithm
        queue<int>que;
        vector<int>indegree(numCourses,0);

        for (int u=0;u<numCourses;u++){
            for (auto v:adj[u]){
                indegree[v]++;
            }
        }
        int cnt=0;
        //fill que, indegree with 0
        for (int i=0;i<numCourses;i++){
            if (indegree[i]==0){
                que.push(i);
                cnt++;
            }
        }
        // simple bfs
        while(que.size()>0){
            int u=que.front();
            que.pop();
            for (auto v:adj[u]){
                indegree[v]--;
                if (indegree[v]==0){
                    que.push(v);
                    cnt++;
                    }
            }
        }
        
        if (cnt==numCourses)return true;
        else return false;


    }
};