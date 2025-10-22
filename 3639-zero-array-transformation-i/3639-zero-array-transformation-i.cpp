class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>dp(n,0);
        for(int i =0;i<queries.size();i++){
            int  l = queries[i][0];
            int r = queries[i][1];
            dp[l]-=1;
            if(r+1<n) dp[r+1]+=1;
        }

        for(int i=1;i<n;i++){
             dp[i]=dp[i-1]+dp[i];
        }
        for(int i=0;i<n;i++){
            cout<<dp[i]<<" ";
        }
        for(int i=0;i<n;i++){
            if(nums[i]+dp[i]>0)return false;
        }
        return true;
    }
};