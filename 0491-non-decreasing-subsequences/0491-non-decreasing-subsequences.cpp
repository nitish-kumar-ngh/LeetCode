class Solution {
public:
   set<vector<int>>s;
   int n;
   void f(int idx,vector<int>& nums,vector<int>&temp){
   // if (idx>=n)return;
    if(temp.size()>=2){
        s.insert(temp);
    }
    for(int i=idx;i<n;i++){
  if (temp.empty()||nums[i]>=temp.back()){
        temp.push_back(nums[i]);
        f(i+1,nums,temp);
        temp.pop_back();
     
    }
    
    }
    
   }

    // void f(int idx, vector<int>& nums, vector<int>& temp) {
    //     if (temp.size() >= 2) {
    //         s.insert(temp);
    //     }

    //     for (int i = idx; i < n; i++) {
    //         if (temp.empty() || nums[i] >= temp.back()) {
    //             temp.push_back(nums[i]);
    //             f(i + 1, nums, temp);
    //             temp.pop_back();
    //         }
    //     }
    // }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        s.clear();
       n=nums.size();
       vector<int>temp;
       f(0,nums,temp);
       vector<vector<int>> result;
       for(auto &v:s){
        result.push_back(v);
       }
       return result;

    }
};