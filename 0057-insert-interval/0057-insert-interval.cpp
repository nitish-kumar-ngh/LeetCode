class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
         vector<vector<int>> ans;
         for(int i=0;i<intervals.size();i++){
            if (ans.empty()||ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            ans.back()[1]=max( ans.back()[1],intervals[i][1]);
         }
         return ans;
    }
};