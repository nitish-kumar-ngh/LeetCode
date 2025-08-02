class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int pivot=-1;
        for(int i=n-1;i>=1;i--){
            if(nums[i-1]<nums[i]){
                pivot = i-1;
                break;
            }
        }
        if (pivot!=-1){
             for(int i=n-1;i>=pivot+1;i--){
            if(nums[i]>nums[pivot]){
               swap(nums[pivot],nums[i]);
                break;
            }
        }
        reverse(nums.begin()+pivot+1,nums.end());
        }
        if(pivot==-1) reverse(nums.begin()+pivot+1,nums.end());
    }
};