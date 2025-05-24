class Solution {
public:
    typedef pair<int, pair<int, int>> p;

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int,int>>qury;
       
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<queries.size();i++){
            qury.push_back({queries[i],i});
        }
        int point =0;
         vector<int>ans(qury.size(),0);
        sort(qury.begin(),qury.end());
        priority_queue<p,vector<p>,greater<p>>pq;
        int dx[]={0,1,-1,0};
        int dy[]={1,0,0,-1};
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        for(int i=0;i<qury.size();i++){
          int num=qury[i].first;
          int idx=qury[i].second;
          
          while(pq.size()>0){
            int numberontop=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            if (numberontop<num){
                point++;
                 pq.pop();
                for(int j=0;j<4;j++){
                    int x_=x+dx[j];
                    int y_=y+dy[j];
                    if (x_>=0 && y_>=0 && x_<grid.size() && y_<grid[0].size() && vis[x_][y_]==0){
                        pq.push({grid[x_][y_],{x_,y_}});
                        vis[x_][y_]=1;
                    }
                }
               
                }
            else break;
          }
         ans[idx]=point;


        }
        return ans;
    }
};