class Solution {
public:
    set<vector<int>>s;
    void f(int idx,vector<int>& nums,vector<int>temp){
        if (idx>=nums.size()){
            s.insert(temp);
            return;
        }
        temp.push_back(nums[idx]);
        f(idx+1,nums,temp);
        temp.pop_back();
        f(idx+1,nums,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        f(0,nums,{});
          vector<vector<int>>ans;
          for(auto c:s){
            ans.push_back(c);
          }
          return ans;
    }
};