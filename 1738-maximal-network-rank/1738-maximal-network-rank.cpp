class Solution {
public:

    class ds {
   
    public:
     vector<int>parent;
    vector<int>rank;
    ds(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find_parent(int x){
        if(parent[x]==x)return x;
        return parent[x]= find_parent(parent[x]);
    }

    void union_by_rank(int x,int y){
        int ulp_x = find_parent(x);
        int ulp_y=find_parent(y);
        if(ulp_x==ulp_y)return;
        if(rank[ulp_x]>rank[ulp_y]){
            parent[ulp_y]=ulp_x;
        }else if(rank[ulp_x]<rank[ulp_y]){
                 parent[ulp_x]=ulp_y;
        }else{
             parent[ulp_x]=ulp_y;
             rank[ulp_y]++;
        }
    }
    
    
    };
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>in(n,0);
        ds DS(n);
        set<pair<int,int>>s;
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            s.insert({u,v});
            s.insert({v,u});
            if(DS.find_parent(u)!=DS.find_parent(v)){
                DS.union_by_rank(u,v);
            }
            in[u]++;
            in[v]++;

        }
        int ans =0;
         
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              if(DS.parent[i]==DS.parent[j]){
                if(s.find({i,j})!=s.end()) ans=max(ans,in[i]+in[j]-1);
                else {
                    ans=max(ans,in[i]+in[j]);
                }
              }else{
                  ans=max(ans,in[i]+in[j]);
              }
            }
        }
        return ans;
    }
};