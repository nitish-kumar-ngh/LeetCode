class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int minLen=INT_MAX;
        int x=0;
        while (j<nums.size()){
            x=x+nums[j];
            if (x>=target){
                minLen=min(minLen,j-i+1);
                j=i;
                i++;
                
                x=0;
                
            }
            j++;
        }
        return minLen==INT_MAX?0:minLen;

    }
};