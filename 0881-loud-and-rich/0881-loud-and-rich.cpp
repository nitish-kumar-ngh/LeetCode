class Solution {
public:
    int t[502];

    int dfs(int node, unordered_map<int,vector<int>>& adj, vector<int>& quiet) {
        if (t[node] != -1) return t[node];

        int ind = node;
        int quit = quiet[node];

        for (auto &it : adj[node]) {
            int candidate = dfs(it, adj, quiet);
            if (quiet[candidate] < quit) {
                quit = quiet[candidate];
                ind = candidate;
            }
        }

        t[node] = ind;
        return ind;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        memset(t, -1, sizeof(t));

        unordered_map<int,vector<int>> adj;
        for (auto &r : richer) {
            int a = r[0], b = r[1];
            adj[b].push_back(a);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(dfs(i, adj, quiet));
        }
        return ans;
    }
};
