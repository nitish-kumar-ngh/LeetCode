class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>v;
        int a=0;
        for(int i=0;i<nums.size();i++){
          a=a^nums[i];
          v.push_back(a);
        }
        int mx=pow(2,maximumBit)-1;
        vector<int >ans;
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i]^mx);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};