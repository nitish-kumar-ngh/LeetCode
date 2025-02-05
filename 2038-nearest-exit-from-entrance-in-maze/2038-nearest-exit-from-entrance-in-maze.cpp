class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        priority_queue<p, vector<p>, greater<p>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (i==0 || i==m-1 ||j==0 || j==n-1){
                if (maze[i][j]=='.'){
                    if (i==entrance[0]&&j==entrance[1])continue;
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }}
            }
        }
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};
        while(q.size()>0){
            auto a=q.top();
            int d=a.first;
            int x=a.second.first;
            int y=a.second.second;
            q.pop();
            if (x==entrance[0] && y==entrance[1])return d;
            for (int j=0;j<4;j++){
                int new_x=x+dx[j];
                int new_y=y+dy[j];
                if (new_x>=0 && new_y>=0 && new_x<m && new_y<n &&maze[new_x][new_y]=='.' && vis[new_x][new_y]==0){
                    q.push({d+1,{new_x,new_y}});
                    vis[new_x][new_y]=1;
                }
            }
   
        }
        return -1;
    }
};