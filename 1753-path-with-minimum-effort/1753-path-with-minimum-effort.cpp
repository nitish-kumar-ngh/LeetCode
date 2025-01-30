class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>ans(m,vector<int>(n,1e9));
        int dx[]={0,1,-1,0};
        int dy[]={1,0,0,-1};
        ans[0][0]=0;
        q.push({0,{0,0}});
        while(q.size()>0){
            auto v=q.top();
            q.pop();
            int d=v.first;
            int x=v.second.first;
            int y=v.second.second;
            
            for(int i=0;i<4;i++){
                int x_=x+dx[i];
                int y_=y+dy[i];
                if (x_<m &&y_<n &&x_>=0 &&y_>=0){
                    int diff=abs(heights[x_][y_]-heights[x][y]);
                    int newdist=max(d,diff);
                     if (ans[x_][y_]>newdist){
                        q.push({newdist,{x_,y_}});
                        ans[x_][y_]=newdist;
                        }
                }
            }
            
        }
        return ans[m-1][n-1];
    }
};