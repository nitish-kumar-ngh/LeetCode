class Solution {
public:
   int lower_bound(vector<int>& nums){
    int ans=nums.size();
    int l=0;
    int h=nums.size()-1;
    while(l<=h){
        int mid=(l+h)/2;
        if (nums[mid]>=0){
            ans=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
   }
    int upper_bound(vector<int>& nums){
    int ans=nums.size();
    int l=0;
    int h=nums.size()-1;
    while(l<=h){
        int mid=(l+h)/2;
        if (nums[mid]>0){
            ans=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
   }
    int maximumCount(vector<int>& nums) {
               int positiveCount = nums.size() - upper_bound(nums);
        // All integers from the index 0 to index before the first zero index
        // will be negative.
        int negativeCount = lower_bound(nums);

        return max(positiveCount, negativeCount);
    }
};