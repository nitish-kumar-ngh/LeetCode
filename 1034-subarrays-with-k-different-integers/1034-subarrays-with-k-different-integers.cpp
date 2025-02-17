class Solution {
public:
    int f(vector<int>& nums,int k){
        int ans=0;
        int l=0;
        int r=0;
        unordered_map<int,int>mp;
        while(r<nums.size()){
          mp[nums[r]]++;
          while(mp.size()>k){
            mp[nums[l]]--;
            if(mp[nums[l]]==0)mp.erase(nums[l]);
            l++;
          }
       ans+=r-l+1;
          r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};