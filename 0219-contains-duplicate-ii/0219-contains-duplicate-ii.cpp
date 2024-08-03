class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        int j=0;
        unordered_set<int>s;
        while (j<n){
            if (j-i>k){
                s.erase(nums[i]);
                i++;
            }
            //past
            if (s.find(nums[j])!=s.end()){
                return true;
            }
            s.insert(nums[j]);
            j++;
        }
        return false;
    }
};