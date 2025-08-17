class Solution {
public:
    int n,m;
    int t[80][80][80];
    int f(int i,int j1,int j2,vector<vector<int>>& grid){

        if(i<0||i>=n || j1<0 ||j1>=m || j2<0 ||j2>=m )return -1e8;
        if(i==n-1){
            if(j1==j2)return t[i][j1][j2]=grid[i][j1];
            else return t[i][j1][j2]=grid[i][j1]+grid[i][j2];
        }
        if(t[i][j1][j2]!=-1)return t[i][j1][j2];
        int ans=-1e8;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                if(j1==j2){
                    ans=max(ans,grid[i][j1]+f(i+1,j1+dj1,j2+dj2,grid));
                }else{
                    ans=max(ans,grid[i][j1]+grid[i][j2]+f(i+1,j1+dj1,j2+dj2,grid));
                }
            }
        }
        return t[i][j1][j2]= ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        n=grid.size();
        m=grid[0].size();
        return f(0,0,m-1,grid);
    }
};