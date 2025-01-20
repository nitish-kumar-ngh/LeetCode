class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<int>R(row,0);
        vector<int>C(col,0);
        unordered_map<int,pair<int,int>>mp;
        for (int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mp[mat[i][j]]={i,j};
            }
        }
         for (int i=0;i<arr.size();i++){
             int r= mp[arr[i]].first;
             int c= mp[arr[i]].second;
               R[r]++;
               C[c]++;
               if (C[c]==row||R[r]==col)return i;
         }
         return 0;
    }
};