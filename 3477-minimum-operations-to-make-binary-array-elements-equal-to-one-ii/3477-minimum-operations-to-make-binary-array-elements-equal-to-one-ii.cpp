class Solution {
public:
    int minOperations(vector<int>& nums) {
         int flips=0;
         int ops=0;
         for(int i=0;i<nums.size();i++){
            nums[i]=flips%2==0?nums[i]:!nums[i];
            if(nums[i]==0){
                flips++;
                ops++;
            }
         }
         return ops;
    }
};