class Solution {
public:
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{entrance[0],entrance[1]}});
    int r = maze.size();
    int c = maze[0].size();
    vector<vector<int>>vis(r,vector<int>(c,0));
    vis[entrance[0]][entrance[1]]=1;
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    while(q.size()>0){

        int d = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if((x!=entrance[0] || y!=entrance[1]) && (x==r-1||x==0||y==c-1||y==0 )  )return d;

        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx>=0 && newx<r && newy>=0&& newy<c && vis[newx][newy]==0 && maze[newx][newy]=='.'){
                q.push({d+1,{newx,newy}});
                vis[newx][newy]=1;
            }
        }

    }    
    return -1;
    }
};