class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
       int l =0;
       int r = 0;
       int ans =0;
       int mask =0;
       while(r<nums.size()){
       
          while((mask & nums[r])!=0){
            mask = mask ^nums[l];
            l++;
          }
             mask = mask|nums[r];
        ans=max(ans,r-l+1);
          r++;
        
       } 
       return ans;
    }
};