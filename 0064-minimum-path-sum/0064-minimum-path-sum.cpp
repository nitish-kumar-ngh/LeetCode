class Solution {
public:
int m,n;
  int t[205][205];
    int f(int i,int j,vector<vector<int>>& grid){
        if (i>=m || j>=n)return INT_MAX;
        if (i==m-1 && j==n-1)return grid[i][j];
        if (t[i][j]!=-1)return t[i][j];
        return t[i][j]= grid[i][j]+min(f(i+1,j,grid),f(i,j+1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
         n=grid[0].size();
         memset(t,-1,sizeof(t));
        return f(0,0,grid);
    }
};