class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        ans.push_back(0);
        int a=0;
        for(int i=0 ;i<arr.size();i++){
            a=a^arr[i];
            ans.push_back(a);
        }
        vector<int>answer(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r= queries[i][1];
            answer[i]= ans[r+1]^ans[l];
        }
        return answer;
    }
};