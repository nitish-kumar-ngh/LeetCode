class Solution {
public:
   int result=0,noObobstacles=0;
   int m,n;
   vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
   void f(int i,int j,int count,vector<vector<int>>& grid){
    if (i<0||i>=m||j<0||j>=n||grid[i][j]==-1){
        return;
    }
    if (grid[i][j]==2){
        if (noObobstacles==count)result++;
        return;
    }
    //backtraking
    grid[i][j]=-1;
for(auto &d:dir){
    int new_i=d[0]+i;
    int new_j=j+d[1];
    f(new_i,new_j,count+1,grid);
}
    grid[i][j]=0;
   }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int start_i=0;
        int start_j=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)noObobstacles++;
                if(grid[i][j]==1){
                    start_i=i;
                    start_j=j;
                }
            }
        }
        noObobstacles++;
        f(start_i,start_j,0,grid);
        return result;
    }
};