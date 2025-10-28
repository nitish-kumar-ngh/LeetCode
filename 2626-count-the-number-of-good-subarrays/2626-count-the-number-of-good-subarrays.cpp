class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans =0;
        int  l =0;
        int r =0;
        int n = nums.size();
        unordered_map<int,int>mp;
        int pairs =0;
        while(r<n){
            pairs+=mp[nums[r]];
            mp[nums[r]]++;
            while(pairs>=k){
                ans=ans+(n-r);
                mp[nums[l]]--;
                pairs-=mp[nums[l]];
                l++;
            }
            r++;
            
            

        }
        return ans;

    }
};