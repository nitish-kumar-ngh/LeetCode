class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        if(s.size()==1)return 0;
        else return 1;
    }
};