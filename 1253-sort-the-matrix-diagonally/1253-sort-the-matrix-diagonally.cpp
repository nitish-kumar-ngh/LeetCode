class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
     
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> ans(row,vector<int>(col,0));
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
               mp[i-j].push_back(mat[i][j]);
            }
        }
        //sort
        for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
        }
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                ans[i][j]=mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return ans;
    }
};