class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minIndex=-1;
        int maxIndex=-1;
        int culpritIndex=-1;
       long long  int ans=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]<minK || nums[i]>maxK)culpritIndex=i;
            if (nums[i]==minK)minIndex=i;
            if (nums[i]==maxK)maxIndex=i;
            int smaller=min(minIndex,maxIndex);
            int temp=smaller-culpritIndex;
            if (temp>0)ans+=temp;
        }
        return ans;
    }
};