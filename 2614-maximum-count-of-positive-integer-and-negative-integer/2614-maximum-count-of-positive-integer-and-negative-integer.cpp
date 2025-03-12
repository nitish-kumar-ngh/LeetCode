class Solution {
public:
   int lowerbound(vector<int>& nums){
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
    int upperbound(vector<int>& nums){
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
               int positiveCount = nums.size() - upperbound(nums);
        int negativeCount = lowerbound(nums);

        return max(positiveCount, negativeCount);
    }
};