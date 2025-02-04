// dsu
class Disjointset{
public:
vector<int>parent;
vector<int>size;
vector<int>rank;
Disjointset(int n){
    parent.resize(n,0);
    rank.resize(n,0);
    size.resize(n,0);
    for (int i=0;i<n;i++){
        parent[i]=i;
        size[i]=1;
    }

}
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
    }else{
        parent[ulp_v]=ulp_u;
        rank[ulp_u]++;
    }
}

};



class Solution {
public:
    
    int removeStones(vector<vector<int>>& stones) {
        int mxrow=0;
        int mxcol=0;
        for(auto it:stones){
            mxrow=max(mxrow,it[0]);
            mxcol=max(mxcol,it[1]);
    }
        int n=mxrow+mxcol+2;
        Disjointset ds(n);
        int cnt=0;
        unordered_map<int,int>mp;
        for (auto it:stones){
            cnt++;
            int noderow=it[0];
            int nodecol=it[1]+mxrow+1;
            ds.union_by_rank(noderow,nodecol);
            mp[noderow]=1;
            mp[nodecol]=1;

        }
        int nc=0;
        // for(int i=0;i<n;i++){
        //     if (ds.parent[ds.find_parent(i)]==i)nc++;
        // }
        for(auto it:mp){
            if (ds.find_parent(it.first)==it.first)nc++;

        }
        return cnt-nc;
    }
};