class Solution {
public:
   vector<vector<int> >dp;
   vector<vector<int> >grid;
   int f(int i,int j){
    int r=grid.size();
    int c=grid[0].size();
    if (i==r-1 and j==c-1)return 1;
    if (dp[i][j]!=-1)return dp[i][j];
    if (i>=r || j>=c ||i<0 || j<0)return 0;
    return dp[i][j]=f(i+1,j) + f(i,j+1);
   }
    int uniquePaths(int m, int n) {
        grid.clear();
        grid.resize(m,vector<int>(n,0));
         dp.resize(105,vector<int>(105,-1));
        return f(0,0);
    }
};