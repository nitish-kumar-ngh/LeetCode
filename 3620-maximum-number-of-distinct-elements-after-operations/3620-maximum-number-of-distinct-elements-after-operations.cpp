class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int prev = -1e9;
        int ans =0;
        for(int i=0;i<n;i++){
            if(prev<nums[i]-k){
                prev =nums[i]-k;
                ans++;
            }else if(prev<nums[i]+k){
                prev = prev+1;
                ans++;
            }
        }
   return ans;
    }
};