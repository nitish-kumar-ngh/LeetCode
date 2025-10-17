class Solution {
public:
    class Disjoint {
    public:
    vector<int>rank;
    vector<int>parent;
    Disjoint(int n){
        rank.resize(n,0);
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find_ulp(int x){
        if(parent[x]==x)return x;
        return parent[x]=find_ulp(parent[x]);
    }

    void union_by_rank(int u,int v){
        int ulp_u = find_ulp(u);
        int ulp_v =  find_ulp(v);

        if(ulp_u==ulp_v)return ;
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else if(rank[ulp_u]<rank[ulp_v]){
               parent[ulp_u]=ulp_v;
        }else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
    };
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = 1e9;
        Disjoint ds(n+1);

        for(int i=0;i<roads.size();i++){
            if(ds.find_ulp(roads[i][0]) != ds.find_ulp(roads[i][1])){
                ds.union_by_rank(roads[i][0],roads[i][1]);
            }
        }
        
         for(int i=0;i<roads.size();i++){
             int u = roads[i][0];
             int v = roads[i][1];
             if(ds.find_ulp(u)==ds.find_ulp(v)){
                if(ds.find_ulp(n)==ds.find_ulp(u)){
                    ans= min(ans,roads[i][2]);
                }
             }
        }
        return ans;
    }
};