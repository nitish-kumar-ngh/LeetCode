class Solution {
public: 
     int t[1001][1001];
    int f(vector<vector<int>>& grid,int i,int j,int r,int c){
        if(i<0 || i>=r || j<0 || j>=c)return 0;
           int a =0;
           int b =0;
           int c1 =0;
           if(t[i][j]!=-1)return t[i][j];
         if(i-1>=0 && j+1<c && i-1<r && j+1>=0&& grid[i][j]<grid[i-1][j+1]){
          a = 1+f(grid,i-1,j+1,r,c);
         }
          if(i+1>=0 && j+1<c && i+1<r && j+1>=0&& grid[i][j]<grid[i+1][j+1]){
            b = 1+f(grid,i+1,j+1,r,c);
         }
          if(i>=0 && j+1<c && i<r && j+1>=0&& grid[i][j]<grid[i][j+1]){
            c1 = 1+f(grid,i,j+1,r,c);
         }
         return  t[i][j]=max({a,b,c1});
    }
    int maxMoves(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        int r = grid.size();
        int c = grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
          ans = max(ans,f(grid,i,0,r,c));
        }
        return ans;
    }
};