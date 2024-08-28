class Solution {
public:
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    void bfs(int i,int j,  vector<vector<int>>&vis,vector<vector<int>>& grid1,vector<vector<int>>& grid2,int &cnt,int n,int m){
    queue<pair<int,int>>q;
     int k=0;
    q.push({i,j});
    vis[i][j]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
       
        q.pop();
        for(auto d:dir){
            int x_=x+d[0];
            int y_=y+d[1];
            if (x_>=0 &&y_>=0&&x_<n &&y_<m && vis[x_][y_]==0 && grid2[x_][y_]==1){
               if (grid2[x_][y_]==1 && grid1[x_][y_]==0){
               // return;
                k=1;}

               q.push({x_,y_});
               vis[x_][y_]=1;
            }
        }

    }
    if (k==0)cnt++;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int cnt=0;
        int m=grid1[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid1[i][j]==1 && grid2[i][j]==1){
                    bfs(i,j,vis,grid1,grid2,cnt,n,m);
                }
            }
        }
        return cnt;
    }
};