class Solution {
public:
    vector<int> prefix; 
    vector<vector<int>> dp;

    int rangeSum(int i, int j) {
        return prefix[j+1] - prefix[i];
    }

    int f(int i, int j) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int score1 = rangeSum(i+1, j) - f(i+1, j);

        int score2 = rangeSum(i, j-1) - f(i, j-1);

        return dp[i][j] = max(score1, score2);
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        prefix.resize(n+1, 0);

       
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + stones[i];
        }

        dp.assign(n, vector<int>(n, -1));
        return f(0, n-1);
    }
};
