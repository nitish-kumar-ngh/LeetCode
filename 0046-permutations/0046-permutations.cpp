class Solution {
public:
    void f(int idx,vector<int>&ans,vector<vector<int>>&result,vector<int>& nums,vector<int>&vis){
        if (idx>=nums.size()){
            result.push_back(ans);
            return;
        }
        for (int i=0;i<nums.size();i++){
            if (!vis[i]){
                vis[i]=1;
            ans.push_back(nums[i]);
            f(idx+1,ans,result,nums,vis);
            ans.pop_back();
            vis[i]=0;}
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>>result;
         vector<int>ans;
         vector<int>vis(nums.size(),0);
         f(0,ans,result,nums,vis);
         return result;
    }
};