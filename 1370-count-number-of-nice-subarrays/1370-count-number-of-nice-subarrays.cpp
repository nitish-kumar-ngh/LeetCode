class Solution {
public:
    int f(vector<int>& nums, int k){
        
        int r=0,l=0,sum=0,cnt=0;
        while(r<nums.size()){
            sum+=nums[r]%2;
            while(sum>k){
                sum=sum-nums[l]%2;
                l=l+1;
            }
            cnt=cnt+(r-l+1);
            r++;

        }
        return cnt;

    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int a=f(nums,k);
        int b=f(nums,k-1);
        return abs(a-b);
    }
};