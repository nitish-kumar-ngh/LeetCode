class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum =0;
        int mx =0;
        int l =0;
        int r =0;
        int n = nums.size();
        unordered_map<int,int>mp;
        while(r<n){
            sum+=nums[r];
            mp[nums[r]]++;
            
            while(mp.size()!=r-l+1){
                 sum-=nums[l];
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                   
                }
                 l++;
               
               
            }
             mx=max(mx,sum);
             r++;


        }
        return mx;

    }
};