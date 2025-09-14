class Solution {
public:
    class disjointset {
    public:
        vector<int> parent;
        vector<int> rank;
        disjointset(int n) {
            parent.resize(n+1, 0);
            rank.resize(n+1, 0);
            for (int i=0; i<=n; i++) parent[i] = i;  
        }

        int find_parent(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find_parent(parent[x]);
        }
        void union_by_rank(int x, int y) {
            int ulp_x = find_parent(x);
            int ulp_y = find_parent(y);
            if (ulp_x == ulp_y) return;
            if (rank[ulp_x] > rank[ulp_y]) {
                parent[ulp_y] = ulp_x;
            } else if (rank[ulp_x] < rank[ulp_y]) {
                parent[ulp_x] = ulp_y;
            } else {
                parent[ulp_x] = ulp_y;
                rank[ulp_y]++;
            }
        }
    };

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        disjointset ds(n);
        int a=-1, b=-1;
        vector<int> in(n+1, -1);

        for (int i=0; i<n; i++) {
            int u = edges[i][0], v = edges[i][1];
            if (in[v] == -1) in[v] = i;
            else {
                a = in[v]; 
                b = i;    
            }
        }

       
        for (int i=0; i<n; i++) {
            if (i == b) continue; 
            int u = edges[i][0], v = edges[i][1];
            if (ds.find_parent(u) != ds.find_parent(v)) {
                ds.union_by_rank(u, v);
            } else {
                if (a == -1) return edges[i]; 
                return edges[a];             
            }
        }
        return edges[b]; 
    }
};
