class DisjointSet{
public:
vector<int>rank;
vector<int>parent;
DisjointSet(int n){

rank.resize(n,0);
parent.resize(n,0);
for (int i=0;i<n;i++){
    parent[i]=i;
}}
int find_parent(int x){
    if (x==parent[x])return x;
    return parent[x]=find_parent(parent[x]);
}
void union_by_rank(int u,int v){
    int ulp_u=find_parent(u);
     int ulp_v=find_parent(v);
     if (ulp_u==ulp_v)return;
     if (rank[ulp_u]>rank[ulp_v]){
        parent[ulp_v]=ulp_u;
     }else if (rank[ulp_u]<rank[ulp_v]){
           parent[ulp_u]=ulp_v;
     }else {
           parent[ulp_u]=ulp_v;;
           rank[ulp_v]++;
     }
}

};




class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cnt=0,connecop=0;
        for (auto v:connections){
            int x=v[0];
            int y=v[1];
            if (ds.find_parent(x)==ds.find_parent(y))cnt++;
            else{
                ds.union_by_rank(x,y);
            }
        }

        for (int i=0;i<n;i++){
            if (ds.parent[i]==i)connecop++;
        }
        int ans=connecop-1;
        if (cnt>=ans)return ans;
        else return -1;
    }
};