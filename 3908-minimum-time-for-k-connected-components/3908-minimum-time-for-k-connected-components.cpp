class Solution {
public:

   static bool cmp(vector<int>& a, vector<int>& b) {
    return a[2] > b[2];
}

    class disjointSu{
    public:
    int components;
    vector<int>parent;
    vector<int>rank;
     disjointSu(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        components = n;
        for(int i=0;i<n;i++){
          parent[i]=i;  
        }
     }

     int find_parent(int x){
        if(parent[x]==x)return x;
        return parent[x]=find_parent(parent[x]);
     }

     void union_by_rank(int u,int v){
        int ul_u = find_parent(u);
        int ul_v = find_parent(v);
        if(ul_u==ul_v)return ;
        components--;
        if(rank[ul_u]>rank[ul_v]){
            parent[ul_v] = ul_u;
        }else if(rank[ul_u]<rank[ul_v]){
             parent[ul_u] = ul_v;
        }else{
            parent[ul_u] = ul_v;
            rank[ul_v]++;
        }
        
     }
    };
    int minTime(int n, vector<vector<int>>& edges, int k) {
       disjointSu DSU(n);
       disjointSu dsu(n);

       sort(edges.begin(),edges.end(),cmp);

       for(int i =0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        if(DSU.find_parent(u)==DSU.find_parent(v))continue;
        DSU.union_by_rank(u,v);

       }
       if(DSU.components>=k)return 0;
       
       int ans = 0;
       for(int i =0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        if(dsu.components<k)break;
        if(dsu.find_parent(u)==dsu.find_parent(v))continue;
        dsu.union_by_rank(u,v);
         ans = wt;

       }
        return ans;
    }
};