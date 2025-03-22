class Solution {
public:
  int dx[4]={1,0,-1,0};
  int dy[4]={0,1,0,-1};
  int n,m;
  void dfs (int i,int j,vector<vector<char>>& grid,vector<vector<int>>&vis){
    if (i>=n || j>=m ||i<0 ||j<0||grid[i][j]=='0'||vis[i][j]==1)return;
     vis[i][j]=1;
     for (int d=0;d<4;d++){
        int i_=i+dx[d];
        int j_=j+dy[d];
        dfs(i_,j_,grid,vis);
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
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};