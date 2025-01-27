class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (i==0||j==0||i==m-1||j==n-1){
                    if (grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        int dx[]={0,1,-1,0};
        int dy[]={1,0,0,-1};
        while(q.size()>0){
            auto v=q.front();
            q.pop();
            int x=v.first;
            int y=v.second;
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0 && newy>=0 && newx<m && newy<n && vis[newx][newy]==0 && grid[newx][newy]==1){
                    q.push({newx,newy});
                    vis[newx][newy]=1;
                }
            }

        }
        int cnt=0;
            for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               
                    if (grid[i][j]==1 && vis[i][j]==0){
                        cnt++;
                }
            }
        }
        return cnt;
    }
};