class Solution {
public:
  vector<vector<int>> Grid;
  vector<vector<int>> dp;
    int f(int i,int j){
    int r=Grid.size();
    int c=Grid[0].size();
    if (i>=r || i<0 ||j<0||j>=c)return 0;
    if (Grid[i][j]==1)return 0;
    if (i==r-1 and j==c-1)return 1;
    if (dp[i][j]!= -1)return dp[i][j];
    

     return dp[i][j]= f(i+1,j)+f(i,j+1);



    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      Grid.clear();
      Grid=obstacleGrid;
      dp.clear();
      dp.resize(105,vector<int>(105,-1));
         return f(0,0);
     }

    
};