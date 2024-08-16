class Solution {
public:
   void dfs(int i,int j,vector<vector<char>>& grid){
    if (i<0 || j<0 || i>=grid.size()||j>=grid[0].size() || grid[i][j]=='0'){
        return;
    }
    grid[i][j]='0';
    dfs(i+1,j,grid);
    dfs(i,j+1,grid);
    dfs(i-1,j,grid);
    dfs(i,j-1,grid);
   }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>gri(grid.size(),vector<int>(grid[0].size(),0));
         for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
               gri[i][j]=grid[i][j]-'0';
            }
        }
        int cnt=0;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid);
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