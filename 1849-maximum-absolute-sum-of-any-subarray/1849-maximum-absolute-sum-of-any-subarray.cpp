class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        int mx=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            mx = max(mx,dp[i]);
        }
         for(int i=0;i<n;i++){
           nums[i]=-nums[i];
        }
          vector<int>dp1(n,0);
          dp1[0]=nums[0];
           mx = max(mx,dp1[0]);
    
    for(int i=1;i<n;i++){
            dp1[i]=max(dp1[i-1]+nums[i],nums[i]);
            mx = max(mx,dp1[i]);
        }
        return mx;
    }
};