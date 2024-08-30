class Solution {
public:
    vector<vector<int>> result;
    void f(int idx,vector<int>& candidates, int target,vector<int>temp,int s){
       if (s>target)return;
       if (idx>=candidates.size()){
        if (s==target){
            result.push_back(temp);
            return;
        }
        return;
       }
       temp.push_back(candidates[idx]);
       f(idx,candidates,target,temp,s+candidates[idx]);
       temp.pop_back();
        f(idx+1,candidates,target,temp,s);
       
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        f(0,candidates,target,{},0);
        return result;
    }
};