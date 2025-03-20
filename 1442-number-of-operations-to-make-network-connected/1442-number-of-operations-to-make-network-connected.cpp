class Solution {
public:
    class DisjointSet{
    public:
    vector<int>rank,parent;
    DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
        int Find_ulp(int x){
            if (parent[x]==x)return x;
            return parent[x]=Find_ulp(parent[x]);
        }
        void union_by_size(int u,int v){
            int ulp_u=Find_ulp(u);
            int ulp_v=Find_ulp(v);
            if (ulp_u==ulp_v)return;
            if (rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v]=ulp_u;
            }else if (rank[ulp_u]<rank[ulp_v]){
                 parent[ulp_u]=ulp_v;
            }else{
                 parent[ulp_u]=ulp_v;
                 rank[ulp_v]++;
            }
        }
    };
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cnt=0;
        for(auto v:connections){
            int x=v[0];
            int y=v[1];
            if (ds.Find_ulp(x)==ds.Find_ulp(y))cnt++;
            else ds.union_by_size(x,y);
        }
        int needed=0;
        for (int i=0;i<n;i++){
            if (ds.parent[i]==i)needed++;
        }
        if (cnt>=needed-1)return needed-1;
        return -1;
    }
};