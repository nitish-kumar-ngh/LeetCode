class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            int a=nums[i-1];
            int b=nums[i];
            int x=a&1;
            int y=b&1;
            if (x^y==0)return false;
        }
        return true;
    }
};