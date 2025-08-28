class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        // Build adjacency list + degree count
        vector<int> degree(n, 0);
        unordered_map<int, vector<int>> adj;
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // Start with all leaf nodes
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }

        // Trim leaves layer by layer
        vector<int> result;
        while (!q.empty()) {
            int size = q.size();
            result.clear(); // last processed layer = possible roots
            for (int i = 0; i < size; i++) {
                int node = q.front(); q.pop();
                result.push_back(node);

                // Decrease degree of neighbors
                for (auto &nbr : adj[node]) {
                    degree[nbr]--;
                    if (degree[nbr] == 1) q.push(nbr);
                }
            }
        }

        return result; // The remaining nodes are centroids
    }
};
