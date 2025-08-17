class Solution {
public:
    int dp[101][105][2];
    int f(vector<int>& piles,int idx,int m,bool flag){
        if(idx>=piles.size()) return dp[idx][m][flag]= 0;
     if(dp[idx][m][flag]!=-1)return dp[idx][m][flag];
        int ans = INT_MIN;
        int ans2 = INT_MAX;   // Bob should minimize

        if(flag==true) {
            // Alice's turn (maximize)
            for(int i=1;i<=2*m && idx+i<=piles.size();i++){
                long long answer=0;
                for(int k=0;k<i && idx+k<piles.size();k++){
                    answer += piles[idx+k];   // ✅ fixed indexing
                }
                ans = max(ans, (int)(answer + f(piles, idx+i, max(m,i), false)));  // ✅ max(m,i)
            }
            return dp[idx][m][flag]=ans;
        } 
        else {
            // Bob's turn (minimize Alice's gain)
            for(int i=1;i<=2*m && idx+i<=piles.size();i++){
                long long answer2=0;
                for(int k=0;k<i && idx+k<piles.size();k++){
                    answer2 += piles[idx+k];   // ✅ fixed indexing
                }
                ans2 = min(ans2, f(piles, idx+i, max(m,i), true));  // ✅ Bob doesn't add stones
            }
            return dp[idx][m][flag]=ans2;
        }
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return f(piles,0,1,true);
    }
};
