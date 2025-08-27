class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if(grid[0][0]==1)return -1;
        vector<vector<int>>vis(r,vector<int>(c,0));
        queue<pair<int,pair<int,int>>>q;
        int ans =INT_MAX;
        q.push({1,{0,0}});
        vis[0][0]=1;
        int dx[]= {1,-1,0,0,1,-1,1,-1};
        int dy[]= {0,0,1,-1,-1,1,1,-1};
        while(q.size()>0){
            int dis = q.front().first;
            int x = q.front().second.first;
            int y =q.front().second.second;
            q.pop();
            if(x==r-1 && y==c-1){
                ans=min(ans,dis);
            }
            for(int d =0;d<8;d++){
                int x_ = x+dx[d];
                int y_ = y+dy[d];
                if(x_>=0 && y_>=0 && x_<r && y_<c && grid[x_][y_]==0 && vis[x_][y_]==0){
                    q.push({dis+1,{x_,y_}});
                    vis[x_][y_]=1;
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};