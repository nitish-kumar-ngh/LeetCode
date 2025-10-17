class Solution {
public:
    class Disjoint{
     public:
     vector<int>rank;
     vector<int>parent;
     vector<int>size;

     Disjoint (int n){
        rank.resize(n,0);
        parent.resize(n,0);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

     }
     int find(int x){
        if(parent[x]==x)return x;
        return parent[x]= find(parent[x]);
     }

     void union_by_size(int u,int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u==ulp_v)return ;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }else{
               parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
     }

    };
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans=0;
        Disjoint ds(n);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(ds.find(u)!=ds.find(v)){
                ds.union_by_size(u,v);
            }
        }

       vector<int>v;
       for(int i=0;i<n;i++){
        if(ds.parent[i]==i){
            v.push_back(ds.size[i]);
        }
       } 
       int rem = n;
       for(int i=0;i<v.size();i++){
         ans+=(v[i])*1LL*(rem-v[i]);
         rem=rem-v[i];
       }

        return ans;
       
       
    }
};