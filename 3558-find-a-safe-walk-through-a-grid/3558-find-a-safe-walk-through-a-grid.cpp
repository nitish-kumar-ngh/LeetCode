class Solution {
public:
    int r;
    int c;
    int t[51][51][105];
    bool f(int i,int j,vector<vector<int>>& grid, int health, vector<vector<int>>&vis){
        if(i<0 || i>=r || j<0||j>=c || vis[i][j]==1)return false;
         
        health=health-grid[i][j];
         if(health<1)return false;
          if(i==r-1 && j==c-1 && health>=1)return true;
          if(t[i][j][health]!=-1)return t[i][j][health];
          vis[i][j]=1;
         bool found = f(i+1,j,grid,health,vis) || f(i-1,j,grid,health,vis) ||
                 f(i,j+1,grid,health,vis) || f(i,j-1,grid,health,vis);
          vis[i][j] = 0; 
       return t[i][j][health]=found;
       
        
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        memset(t,-1,sizeof(t));
        r=grid.size();
        c=grid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
       return f(0,0,grid,health,vis);
    }
};