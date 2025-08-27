class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=1;
                }
        }
         for(int i=0;i<r;i++){
            if(board[i][c-1]=='O'){
                q.push({i,c-1});
                vis[i][c-1]=0;
            }
        }

         for(int i=0;i<c;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                vis[0][i]=1;
                }
        }
         for(int i=0;i<c;i++){
            if(board[r-1][i]=='O'){
                q.push({r-1,i});
                vis[r-1][i]=1;
                }
        }
      int dx[]={-1,1,0,0};
      int dy[]={0,0,-1,1};
      while(q.size()>0){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int d =0;d<4;d++){
            int x_ = x+dx[d];
            int y_ = y+dy[d];

            if(x_>=0 && x_<r && y_>=0 && y_<c && board[x_][y_]=='O' && vis[x_][y_]==0){
                q.push({x_,y_});
                vis[x_][y_]=1;
            }
        }

      }
      for(int i=0;i<r;i++){
        for(int j =0;j<c;j++){
            if(board[i][j]=='O'&& vis[i][j]==0 && i!=0 && i!=r-1 && j!=0 && j!=c-1){
                board[i][j]='X';
            }
        }
      }
    }
};