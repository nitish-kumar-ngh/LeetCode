class Solution {
public:
    //sare direction me move kr skte hai 
    vector<vector<int>>directions={{1,1},{1,0},{0,1},{-1,0},{0,-1},{1,-1},{-1,1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

       int level=0;
        int n= grid.size();
        int m= grid[0].size();
        if (n==0||m==0||grid[0][0]!=0)return -1;

        auto isSafe=[&](int x,int y){
            return x<n && y<m && x>=0 &&y>=0 ;
        };
        
        queue<pair<int,int>>que;
        que.push({0,0});//o shell
        grid[0][0]=1;//visit bhi kiya
        while (!que.empty()){
            int N=que.size();
            while(N--){
                auto curr=que.front();
                que.pop();
                int x=curr.first;
                int y=curr.second;
                if (x==n-1&&y==m-1)return level+1;
                //explore neighbour
                for (auto dire:directions){
                    int x_=dire[0]+x;
                    int y_=dire[1]+y;
                    if (isSafe(x_,y_)&&grid[x_][y_]==0){
                        
                        que.push({x_,y_});
                        grid[x_][y_]=1;
                    }

                }

            }
            level++;
        }
   return -1;
    }
};