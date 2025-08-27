class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        int ans =0;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(q.size()>0){
            int dis = q.front().first;
            ans = max(ans,dis);
            int x = q.front().second.first;
            int y =  q.front().second.second;
            q.pop();

            for(int d =0;d<4;d++){
                int x_ = x+dx[d];
                int y_ = y+dy[d];
                if(x_>=0 && x_<r && y_>=0 && y_<c && grid[x_][y_]==1 && vis[x_][y_]==0){
                    q.push({dis+1,{x_,y_}});
                    vis[x_][y_]=1;
                }
            }

        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1 && vis[i][j]==0)return -1;
            }
        }
        return ans;
    }
};