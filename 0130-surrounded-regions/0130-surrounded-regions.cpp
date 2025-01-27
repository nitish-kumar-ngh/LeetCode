class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (i==0 || j==0 ||i==m-1||j==n-1){
                    if (board[i][j]=='O'){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        while(q.size()>0){
            auto v=q.front();
            q.pop();
            int x=v.first;
            int y=v.second;
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if (newx>=0&&newy>=0&&newx<m&&newy<n&&vis[newx][newy]==0&&board[newx][newy]=='O'){
                    q.push({newx,newy});
                    vis[newx][newy]=1;
                }
            }
        }
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                    if (board[i][j]=='O' &&vis[i][j]==0){
                       board[i][j]='X';
                    }
                }
            }
       // return board;
    }
};