class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<pair<int,int>>lessThanPivot;
        vector<pair<int,int>>greaterThanPivot;
         vector<pair<int,int>>equal;
        for(int i=0;i<nums.size();i++){
            if (nums[i]<pivot)lessThanPivot.push_back({i,nums[i]});
            else if (nums[i]>pivot)greaterThanPivot.push_back({i,nums[i]});
            else {
                equal.push_back({i,nums[i]});
        }
        }
        sort(lessThanPivot.begin(),lessThanPivot.end());
         sort(greaterThanPivot.begin(),greaterThanPivot.end());
          sort(equal.begin(),equal.end());
          vector<int>ans;
          for(auto x:lessThanPivot){
            ans.push_back(x.second);
          }
           for(auto x:equal){
            ans.push_back(x.second);
          }
           for(auto x:greaterThanPivot){
            ans.push_back(x.second);
          }
          return ans;
    }
};