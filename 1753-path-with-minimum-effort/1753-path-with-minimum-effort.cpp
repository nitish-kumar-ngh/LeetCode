class Solution {
public:
    typedef pair<int,pair<int,int>>P;
    vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
    
    int m=heights.size();
    int n=heights[0].size();
    auto isSafe=[&](int x,int y){
        return x>=0 && y>=0 && x<m && y<n;
    };
    vector<vector<int>>result(m,vector<int>(n,INT_MAX));

    priority_queue<P,vector<P>,greater<P> >pq;
    pq.push({0,{0,0}});
    result[0][0]=0;
    while(!pq.empty()){
        auto ele=pq.top();
        int diff=ele.first;
        auto coordinate=ele.second;
        int x=coordinate.first;
        int y=coordinate.second;
        pq.pop();
        //neighbour explore
        for (auto dir:directions){
            int x_=x+dir[0];
            int y_=y+dir[1];
            if(isSafe(x_,y_)){
                int newdiff= abs(heights[x][y]-heights[x_][y_]);
                int maxdiff=max(diff,newdiff);
                if (result[x_][y_]>maxdiff){
                    result[x_][y_]=maxdiff;
                    pq.push({maxdiff,{x_,y_}});
                }
            }
        }
    }


     return result[m-1][n-1];

    }
};