class Solution {
public:
 int dx[4]={1,0,-1,0};
 int dy[4]={0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();
        int m=grid[0].size();
        int freshcnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j]==2 &&!vis[i][j]){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }else if (grid[i][j]==1)freshcnt++;
            }
        }
        int ans=0;
        int cnt=0;
        while(q.size()>0){
            auto v=q.front();
            q.pop();
            int time=v.first;
            int x=v.second.first;
            int y=v.second.second;
            ans=max(ans,time);
            for (int i=0;i<4;i++){
                int x_=x+dx[i];
                int y_=y+dy[i];
                if (x_>=0 && y_>=0 && x_<n &&y_<m && grid[x_][y_]==1 && !vis[x_][y_]){
                    q.push({time+1,{x_,y_}});
                    vis[x_][y_]=1;
                    cnt++;
                }
            }
     
        }
        if (cnt==freshcnt)return ans;
         else return -1;
    }
};