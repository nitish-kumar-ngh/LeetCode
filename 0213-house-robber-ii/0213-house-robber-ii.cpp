class Solution {
public:
    int n;
    int t[101];
    int f(int idx,vector<int>& nums){
        if(idx>=n)return 0;
        if(t[idx]!=-1)return t[idx];
        int ans= INT_MIN;
        ans=max(ans,nums[idx]+f(idx+2,nums));
        ans=max(ans,f(idx+1,nums));
        return t[idx]=ans;
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(t,-1,sizeof(t));
        if(n==1)return nums[0];
         int ans = INT_MIN;
       ans= max(ans,f(1,nums));
       nums.pop_back();
        n = nums.size();
         memset(t,-1,sizeof(t));
       ans= max(ans,f(0,nums));
       return ans;
    }
};