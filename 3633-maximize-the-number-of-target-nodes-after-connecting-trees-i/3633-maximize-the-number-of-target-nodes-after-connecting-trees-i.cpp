class Solution {
public:
   void bfs(int node, vector<int>& ans, unordered_map<int, vector<int>>& adj, int k) {
    if (k < 0) return;
    queue<pair<int, int>> q;
    unordered_set<int> vis;
    q.push({node, 0});
    vis.insert(node);

    while (!q.empty()) {
        auto [a, dist] = q.front();
        q.pop();
        ans[node]++;  // or ans[a]++ depending on what you're counting

        if (dist == k) continue;  // stop expanding beyond k

        for (auto& nei : adj[a]) {
            if (!vis.count(nei)) {
                vis.insert(nei);
                q.push({nei, dist + 1});
            }
        }
    }
}

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        unordered_map<int, vector<int>> adj1, adj2;
        int n = 0, m = 0;

        for (auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
            n = max(n, max(e[0], e[1]));
        }

        for (auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
            m = max(m, max(e[0], e[1]));
        }

        n++; m++;
        vector<int> ans1(n, 0), ans2(m, 0);

        for (int i = 0; i < n; i++) bfs(i, ans1, adj1, k);
        for (int i = 0; i < m; i++) bfs(i, ans2, adj2, k - 1);
         int an = 0;
        
        for (int i = 0; i < m; i++) an=max(an,ans2[i]);
         for (int i = 0; i < n; i++)  ans1[i]=ans1[i]+an;
      

        return ans1;
    }
};
