class Solution {
public:
    int t[201][201];
    int f (int m,int n,vector<vector<int>>& grid,int i,int j){
       if (i==m-1 && j==n-1)return grid[i][j];
        if (i>=m || j>=n)return 1000000;
        if (t[i][j]!=-1)return t[i][j];
        int ans =0;
         int right=grid[i][j]+f(m,n,grid,i,j+1);
        int left= grid[i][j]+f(m,n,grid,i+1,j);
      //  return grid[i][j]+min(f(m,n,grid,i,j+1),f(m,n,grid,i+1,j));
      return t[i][j]=min(right,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(t,-1,sizeof(t));
        return f(m,n,grid,0,0);
    }
};