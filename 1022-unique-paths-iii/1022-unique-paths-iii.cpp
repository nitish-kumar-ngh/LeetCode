class Solution {
public:
    int f(int i,int j,int desi,int desj,int &non_obstacle,vector<vector<int>>& grid, vector<vector<int>>&vis,int r,int c,int obs){
        
       // if(i<0 || j<0 || i>=r || j>=c || grid[i][j]==-1 || vis[i][j]==1)return 0;
        if(i==desi && j==desj ){
            if(obs==non_obstacle)return 1;
            else return 0;
        }
        int ans =0;
        if(i+1<r && grid[i+1][j]!=-1 &&vis[i+1][j]==0 ){
            vis[i+1][j]=1;
           ans+= f(i+1,j,desi,desj,non_obstacle,grid,vis,r,c,obs+1);
           vis[i+1][j]=0;

        }
         if(j+1<c && grid[i][j+1]!=-1 && vis[i][j+1]==0 ){
            vis[i][j+1]=1;
           ans+= f(i,j+1,desi,desj,non_obstacle,grid,vis,r,c,obs+1);
           vis[i][j+1]=0;

        }
         if(i-1>=0 && grid[i-1][j]!=-1 && vis[i-1][j]==0 ){
            vis[i-1][j]=1;
           ans+= f(i-1,j,desi,desj,non_obstacle,grid,vis,r,c,obs+1);
           vis[i-1][j]=0;

        }
         if(j-1>=0 && grid[i][j-1]!=-1 &&vis[i][j-1]==0){
            vis[i][j-1]=1;
           ans+= f(i,j-1,desi,desj,non_obstacle,grid,vis,r,c,obs+1);
           vis[i][j-1]=0;

        }
        return ans;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int non_obstacle =0;
        int r = grid.size();
        int c = grid[0].size();
        int srci=0;
        int srcj=0;
        int desi=0;
        int desj=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]!=-1){
                    non_obstacle++;
                }
                 if (grid[i][j]==1){
                    srci = i;
                    srcj = j;
                 }
                 if(grid[i][j]==2){
                    desi = i;
                    desj = j;
                }
            }
        }
        vector<vector<int>>vis(r,vector<int>(c,0));
          vis[srci][srcj] = 1;
       return  f(srci,srcj,desi,desj,non_obstacle,grid,vis,r,c,1);
        
    }
};