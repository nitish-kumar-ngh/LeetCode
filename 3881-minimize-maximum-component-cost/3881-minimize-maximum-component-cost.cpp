class Solution {
public:
  class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int cc ;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        cc=n;
    }
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    void union_by_rank(int u,int v){
        int upu = find(u);  // fix here
        int upv = find(v);  // fix here

        if(upu==upv)return;
        if(rank[upu]>rank[upv]){
            parent[upv]=upu;
        }else if(rank[upu]<rank[upv]){
            parent[upu]=upv;
        }else{
            parent[upu]=upv;
            rank[upv]++;   // fix here
        }
        cc--;
    }
};

    int minCost(int n, vector<vector<int>>& edges, int k) {
        DSU d(n);
        sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });
        int ans =0;
        for(int i=0;i<edges.size();i++){
            if(d.cc==k)return ans;
            int xp=d.find(edges[i][0]);
            int yp=d.find(edges[i][1]);
            if(xp==yp){
                continue;
            }else{
                d.union_by_rank(edges[i][0],edges[i][1]);
                ans=max(ans,edges[i][2]);
            }
        }
        return ans;
    }
};