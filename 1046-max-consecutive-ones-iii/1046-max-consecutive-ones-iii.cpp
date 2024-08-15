class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int maxLen=0;
        unordered_map<int ,int>mp;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp[0]>k){
                mp[nums[l]]--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};