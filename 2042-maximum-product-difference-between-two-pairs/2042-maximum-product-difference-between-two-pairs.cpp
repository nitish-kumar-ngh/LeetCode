class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[0];
        int b=nums[1];
        int c=nums[nums.size()-1];
        int d=nums[nums.size()-2];
        return (c*d)-(a*b);
    }
};