class Solution {
public:
    vector<pair<int,int> >P;
    void dfs(vector<vector<int>>& grid,int sr,int sc,int iC,int finalColor){
        int row=grid.size();
        int col=grid[0].size();
        if (sr<0 || sc <0|| sr>=row || sc>=col || grid[sr][sc]!=iC){
             return;
        }
        
        grid[sr][sc]=-finalColor;
       dfs(grid,sr+1,sc,iC,finalColor);
       dfs(grid,sr,sc+1,iC,finalColor);
       dfs(grid,sr-1,sc,iC,finalColor);
       dfs(grid,sr,sc-1,iC,finalColor);
       
       // below code will run after all dfs
       if (not(sr==0 || sc==0 || sr == row-1 || sc==col-1||grid[sr+1][sc]!=-finalColor || grid[sr-1][sc]!=-finalColor || grid[sr][sc-1]!=-finalColor||grid[sr][sc+1]!=-finalColor)){
        P.push_back(make_pair(sr,sc));
       }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
         int r=grid.size();
        
        int c=grid[0].size();
        int sr=row;
        int sc=col;
        int iC=grid[sr][sc];
        int finalColor = color;
        if (grid[sr][sc]==color)return grid;
        dfs(grid,sr,sc,iC,finalColor);
        for (auto ele:P){
            int x=ele.first;
            int y=ele.second;
            cout<<x<<y<<" ";
            grid[x][y]=iC;
            
        }
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                if (grid[i][j]<0) grid[i][j]=- grid[i][j];
            }
        }
  
        return grid;

    }
};