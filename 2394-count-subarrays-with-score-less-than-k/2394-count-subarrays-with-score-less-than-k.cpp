class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
         int  l =0;
         int r = 0;
        long long  int sum =0;
        long long cnt =0;
         while(r<nums.size()){
            sum+=nums[r];
            while(sum*(r-l+1)*1LL>=k){
                sum=sum-nums[l];
                l++;
            }
            long long len = (r-l+1);
            cnt = cnt + len;
            r++;
            
         }
         return cnt;
    }
};