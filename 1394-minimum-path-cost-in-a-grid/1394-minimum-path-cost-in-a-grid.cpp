class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int f(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& moveCost) {
        if (r == m-1) return grid[r][c]; // base: last row → just cell value

        if (dp[r][c] != -1) return dp[r][c];

        int answer = INT_MAX;
        for (int nextCol = 0; nextCol < n; nextCol++) {
            int cost = grid[r][c] + moveCost[grid[r][c]][nextCol] 
                       + f(grid, r+1, nextCol, moveCost);
            answer = min(answer, cost);
        }
        return dp[r][c] = answer;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<int>(n, -1));

        int ans = INT_MAX;
        for (int c = 0; c < n; c++) {
            ans = min(ans, f(grid, 0, c, moveCost));
        }
        return ans;
    }
};
