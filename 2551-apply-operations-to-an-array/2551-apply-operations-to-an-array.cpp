class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if (nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }
      //  return nums;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if (nums[i]!=0)v.push_back(nums[i]);
        }
         for(int i=0;i<nums.size();i++){
            if (nums[i]==0)v.push_back(nums[i]);
        }
        return v;
    }
};