class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = INT_MIN;
        int r = accounts.size();
        int c = accounts[0].size();

        for(int i=0;i<r;i++){
            int s =0;
            for(int j =0;j<c;j++){
                s+=accounts[i][j];
            }
            ans=max(ans,s);
        }
        return ans;
    }
};