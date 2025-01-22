class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
         vector<vector<int>> ans(m,vector<int>(n,0));
          vector<vector<int>> vis(m,vector<int>(n,0));
     //   priority_queue<pair<pair<int,int>,int>>pq;
     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        for (int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]){
                    pq.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        while(!pq.empty()){
         auto v=pq.top();
         int d=v.first;
         int y=v.second.second;
         int x=v.second.first;
         pq.pop();
        // ans[x][y]=d;
         int dx[]={0,-1,1,0};
         int dy[]={-1,0,0,1};
         for (int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if (newx>=0&&newy>=0&&newx<m&&newy<n&&vis[newx][newy]==0){
                ans[newx][newy]=d+1;
                 pq.push({d+1,{newx,newy}});
                    vis[newx][newy]=1;
            }


         }

        }
       return ans;

    }
};