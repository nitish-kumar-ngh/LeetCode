class Solution {
public:
  int dx[4]={1,0,-1,0};
  int dy[4]={0,1,0,-1};
  int n,m;
  void bfs (int i,int j,vector<vector<char>>& grid,vector<vector<int>>&vis){
    queue<pair<int,int>>q;
    q.push({i,j});
    vis[i][j]=1;
    while(q.size()>0){
    auto v=q.front();
    q.pop();

     for (int d=0;d<4;d++){
        int i_=v.first+dx[d];
        int j_=v.second+dy[d];
        if (i_>=0 &&j_>=0&&i_<n&&j_<m&&vis[i_][j_]==0&&grid[i_][j_]=='1'){
            q.push({i_,j_});
            vis[i_][j_]=1;
        }
        
     }
  }

     
  }
    int numIslands(vector<vector<char>>& grid) {
         n=grid.size();
         m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j]=='1'&& !vis[i][j]){
                    bfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};