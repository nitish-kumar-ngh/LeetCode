class Solution {
public:

    void bfs(unordered_map<int,vector<int> >&mp,int u, vector <bool>&visited){
        queue<int>que;
        que.push(u);
        visited[u]=true;
        while(que.size()>0){
            auto u=que.front();
            que.pop();
            for (auto v:mp[u]){
               if (!visited[v]){
                    que.push(v);
                    visited[v]=true;
                }
            }

        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
          int n=rooms.size();
          //graph banao
          unordered_map<int,vector<int> >mp;
          for (int i=0;i<n;i++){
            for (auto v:rooms[i]){
                mp[i].push_back(v);
            }
          }
          int cnt=0;
          vector <bool>visited(n,false);
          for (int i=0;i<n;i++){
            if (!visited[i]){
                 bfs(mp,0,visited);
                 cnt++;
            }
          }
         
          if (cnt<=1)return true;
          return false;
    }
};