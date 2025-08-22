class Solution {
public:
    int t[5001][4][3];
    int MOD = 1e9 + 7;
    vector<pair<int, int>> moves = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    int f(int n, int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= 4 || j < 0 || j >= 3 || grid[i][j] == -1) return 0;
        if (n == 1) return 1;

        if (t[n][i][j] != -1) return t[n][i][j];
        long long ans = 0;
        for (auto [dx, dy] : moves) {
            int ni = i + dx;
            int nj = j + dy;
            ans = (ans + f(n - 1, ni, nj, grid)) % MOD;
        }
        return t[n][i][j] = ans;
    }

    int knightDialer(int n) {
        memset(t, -1, sizeof(t));
        vector<vector<int>> grid(4, vector<int>(3, 0));
        grid[3][0] = -1;
        grid[3][2] = -1;

        long long total = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] != -1) {
                    total = (total + f(n, i, j, grid)) % MOD;
                }
            }
        }
        return total;
    }
};
