class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
          int flips=0;
        int flipsatidexi=0;
        for (int i=0;i<nums.size();i++){
            if (i>=k && nums[i-k]==5){
                flipsatidexi--;
            }
            if (flipsatidexi%2==nums[i]){
                if (i+k>nums.size())return -1;
                 flipsatidexi++;
                 flips++;
                 nums[i]=5;
            }
        }
        return flips;
    }
};