class Solution {
public:
    class Disjoint{
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

      int find(int x){
        if(x==parent[x])return x;
        return parent[x]=find(parent[x]);
      }

      void union_by_rank(int u,int v){
        int x = find(u);
        int y = find(v);
        if(x==y)return ;
        if(rank[x]>rank[y]){
            parent[y]=x;

        }else if(rank[y]>rank[x]){
            parent[x]=y;
        }else{
             parent[x]=y;
             rank[y]++;
        }

      }
    };
    class cmp {
        public:
       bool operator()(vector<int>&a,vector<int>&b){
        return a[0]>b[0];
       }
    };
    set<tuple<int,int,int>>s;
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
         Disjoint ds(n+1);
         Disjoint ds2(n+1);
         sort(edges.begin(),edges.end(),cmp());
         int ans =0;
         for(int i=0;i<edges.size();i++){
            int u = edges[i][1];
            int v = edges[i][2];
            if(edges[i][0]==2)continue;
            if(ds.find(u)==ds.find(v))s.insert(make_tuple(edges[i][0],u,v));
            else{
                ds.union_by_rank(u,v);
            }
         }
          for(int i=0;i<edges.size();i++){
            int u = edges[i][1];
            int v = edges[i][2];
            if(edges[i][0]==1)continue;
            if(ds2.find(u)==ds2.find(v))s.insert(make_tuple(edges[i][0],u,v));
            else{
                ds2.union_by_rank(u,v);
            }
         }
     //    if(ans==0)return -1;
     int cnt =0;
     int cnt1=0;
     for(int i=1;i<n+1;i++){
        if(ds.parent[i]==i)cnt++;
        if(ds2.parent[i]==i)cnt1++;
     }
      if(cnt>1 || cnt1>1)return -1;
         return s.size();
    }
};