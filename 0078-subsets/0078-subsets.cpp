class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> v;
        for(int i=0;i<pow(2,n);i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                if(i&1<<j)temp.push_back(nums[j]);
            }
            v.push_back(temp);
        }
        return v;
    }
};