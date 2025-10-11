class Solution {
public:
    #define ll long long
    #define MOD 1000000007

    int rectangleArea(vector<vector<int>>& rectangles) {
        // collect all unique x and y coordinates
        set<int> xs, ys;
        for (auto &r : rectangles) {
            xs.insert(r[0]); xs.insert(r[2]);
            ys.insert(r[1]); ys.insert(r[3]);
        }

        // assign coordinate -> index
        unordered_map<int,int> cx, cy;
        int index = 0;
        for (auto x : xs) cx[x] = index++;
        index = 0;
        for (auto y : ys) cy[y] = index++;

        // store coordinates in vectors (sorted due to set)
        vector<int> x_val(xs.begin(), xs.end());
        vector<int> y_val(ys.begin(), ys.end());

        // visited cells in compressed grid
        vector<vector<bool>> vis(x_val.size(), vector<bool>(y_val.size(), false));

        ll ans = 0;

        // mark covered cells, add area once per cell
        for (auto &r : rectangles) {
            int x1 = cx[r[0]], x2 = cx[r[2]];
            int y1 = cy[r[1]], y2 = cy[r[3]];

            for (int i = x1; i < x2; ++i) {
                for (int j = y1; j < y2; ++j) {
                    if (!vis[i][j]) {
                        ll Width  = (ll)x_val[i + 1] - x_val[i];
                        ll Height = (ll)y_val[j + 1] - y_val[j];
                        ans = (ans + (Width * Height) % MOD) % MOD;
                        vis[i][j] = true;
                    }
                }
            }
        }
        return (int)(ans % MOD);
    }
};
