class Solution {
public:
    typedef tuple<int,int,int,int>p;
    int shortestPath(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        if(grid[0][0]==-1)return -1;
        if(grid[0][0]==0 && r==1 &&c==1)return 0;
        //k,r,c,dist
        vector<vector<int>>dist(r,vector<int>(c,1e9));
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,0,0,0});
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};

        while(pq.size()>0){
           auto [s,i,j,dis]=pq.top();
           pq.pop();
           if(s>k)continue;
           for(int d =0;d<4;d++){
            int x = i+dx[d];
            int y = j +dy[d];
            if(x>=0 &&x<r && y>=0 &&y<c){
                if(dist[x][y]>dis+1  ){
                    dist[x][y]=dis+1;
                  if(grid[x][y]==0){
                    pq.push({s,x,y,dist[x][y]});
                  }else{
                    pq.push({s+1,x,y,dist[x][y]});
                  }
                }
            }
           }
        }
        return dist[r-1][c-1]==1e9?-1:dist[r-1][c-1];
    }
};