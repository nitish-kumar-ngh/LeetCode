class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();//row
        int n=mat[0].size();//col
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for (int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(q.size()>0){
            auto v=q.front();
            int x=v.first.first;
            int y=v.first.second;
            int d=v.second;
            q.pop();
            ans[x][y]=d;
            int dx[]={0,1,0,-1};
            int dy[]={1,0,-1,0};
            for (int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if (newx>=0 &&newy>=0 &&newx<m&&newy<n&&vis[newx][newy]==0){
                    q.push({{newx,newy},d+1});
                    vis[newx][newy]=1;
                }
            }

        }
        return ans;

    }
};