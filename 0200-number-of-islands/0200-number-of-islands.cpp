class Solution {
public:
   void dfs(int i,int j,vector<vector<int>>& gri){
    if (i<0 || j<0 || i>=gri.size()||j>=gri[0].size() || gri[i][j]==0){
        return;
    }
    gri[i][j]=0;
    dfs(i+1,j,gri);
    dfs(i,j+1,gri);
    dfs(i-1,j,gri);
    dfs(i,j-1,gri);
   }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>gri(grid.size(),vector<int>(grid[0].size(),0));
         for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
               gri[i][j]=grid[i][j]-'0';
            }
        }
        int cnt=0;
        for (int i=0;i<gri.size();i++){
            for (int j=0;j<gri[0].size();j++){
                if (gri[i][j]==1){
                    cnt++;
                    dfs(i,j,gri);
                }
            }
        }

        for (int i=0;i<gri.size();i++){
            for (int j=0;j<gri[0].size();j++){
                cout<<gri[i][j]<<" ";
            }
            cout<<"\n";
        }
        return cnt;
    }
};