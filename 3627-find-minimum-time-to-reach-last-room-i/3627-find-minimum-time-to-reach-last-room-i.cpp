class Solution {
public:
    int r, c;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        r = moveTime.size();
        c = moveTime[0].size();
        
        vector<vector<int>> dp(r, vector<int>(c, INT_MAX));
        using T = tuple<int,int,int>; // time, i, j
        priority_queue<T, vector<T>, greater<T>> pq;
        
        dp[0][0] = 0;
        pq.push({0, 0, 0});
        
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        
        while(!pq.empty()){
            auto [t, i, j] = pq.top();
            pq.pop();
            
            if(i == r-1 && j == c-1) return t; // reached goal
            
            if(t > dp[i][j]) continue; // outdated
            
            for(int d=0; d<4; d++){
                int ni = i + dx[d];
                int nj = j + dy[d];
                if(ni < 0 || nj < 0 || ni >= r || nj >= c) continue;
                
                int nextTime = max(t+1, moveTime[ni][nj] + 1);
                if(nextTime < dp[ni][nj]){
                    dp[ni][nj] = nextTime;
                    pq.push({nextTime, ni, nj});
                }
            }
        }
        
        return dp[r-1][c-1]; // unreachable
    }
};
