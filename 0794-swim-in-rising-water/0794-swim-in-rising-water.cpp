class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    int swimInWater(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        int ans = 1e9;
        priority_queue<p,vector<p>,greater<p>>q;
        q.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(q.size()>0){
            int t = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            if(x==r-1 && y==c-1){
                if(ans>t){
                    ans=t;
                }

            }
            for(int i=0;i<4;i++){
                int x_ = x+dx[i];
                int y_= y+dy[i];
                if(x_>=0 && x_<r && y_>=0 && y_<c && vis[x_][y_]==0){
                    q.push({max(t,grid[x_][y_]),{x_,y_}});
                    vis[x_][y_]=1;
                }
            }
        }
        return ans;
    }
};