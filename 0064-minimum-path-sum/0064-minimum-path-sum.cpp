class Solution {
public:
    vector<vector<int>> Grid;
    vector<vector<int>> dp;
    int f(int i,int j){
        int r=Grid.size();
        int c=Grid[0].size();
        if (i==r-1 and j == c-1)return Grid[i][j];
        if (dp[i][j]!= -1)return dp[i][j];
        if (i>=r || j>=c || i<0 || j<0) return INT_MAX;
        
      
        return dp[i][j]= Grid[i][j]+min(f(i+1,j),f(i,j+1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        Grid.clear();
        dp.clear();
        dp.resize(205,vector<int>(205,-1));
        Grid=grid;
        return f(0,0);
    }
};