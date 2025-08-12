class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=nums[0];
        int ans =INT_MIN;
        ans=max(ans,mx);
        for(int i=1;i<nums.size();i++){
           mx=max({mx+nums[i],nums[i]});
           ans=max(ans,mx);
           cout<<mx<<" ";
        }
        return ans;
    }
};