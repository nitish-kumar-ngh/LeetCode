class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
       map<int,vector<int>>mp;
        int row = mat.size();
        int col = mat[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        } 
       vector<int>ans;
       for(auto &it:mp){
        if(it.first % 2==0){
            reverse(it.second.begin(),it.second.end());
        }
       }
       for(auto & it:mp){
        for(int &x:it.second){
            ans.push_back(x);
        }
       }  
       return ans;
    }
};