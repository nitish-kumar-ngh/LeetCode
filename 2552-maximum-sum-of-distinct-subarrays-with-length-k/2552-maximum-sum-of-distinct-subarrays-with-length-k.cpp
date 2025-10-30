class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
    
     unordered_map<int,int>mp;
     int l = 0;
     int r = 0;
     long long sum =0;
     long long ans =0;
     while(r<nums.size()){

        sum+=nums[r];
        mp[nums[r]]++;
        while((r-l+1)>k){
            mp[nums[l]]--;
            sum=sum-nums[l];
            if(mp[nums[l]]==0){
                mp.erase(nums[l]);
            }
            l++;
        }
        if(mp.size()==k)ans=max(ans,sum);
        r++;
     }
     return ans;

    }
};