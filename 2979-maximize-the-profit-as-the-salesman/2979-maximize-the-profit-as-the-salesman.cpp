class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
      
      vector<int>dp(n+1,0);
      vector<vector<vector<int>>>mp(n+1);
      for (auto &a:offers){
        int x=a[0];
        int y=a[1];
        int gold=a[2];
        mp[y+1].push_back({x+1,y+1,gold});
      }
      for (int e=1;e<=n;e++){
        dp[e]=dp[e-1];
        for (auto x:mp[e]){
            dp[e]=max({dp[e],dp[x[0]-1]+x[2]});
        }
      }
        return dp[n];
    }
};