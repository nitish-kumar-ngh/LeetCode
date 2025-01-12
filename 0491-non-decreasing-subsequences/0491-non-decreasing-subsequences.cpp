class Solution {
public:
   set<vector<int>>s;
   int n;
   void f(int idx,vector<int>& nums,vector<int>temp){
    if (idx>=n){
         if(temp.size()>=2){
        s.insert(temp);
    }
    return;
    }
    
    if (temp.empty()||nums[idx]>=temp.back()){
        temp.push_back(nums[idx]);
        f(idx+1,nums,temp);
        temp.pop_back();
        f(idx+1,nums,temp);
    }else{
        f(idx+1,nums,temp);
    }
   }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        s.clear();
       n=nums.size();
       vector<int>temp;
       f(0,nums,{});
       vector<vector<int>> result;
       for(auto &v:s){
        result.push_back(v);
       }
       return result;

    }
};