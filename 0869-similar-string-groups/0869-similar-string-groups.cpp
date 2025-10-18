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
     int find_ulp(int x){
        if(x==parent[x])return x;
        return parent[x]= find_ulp(parent[x]);
     }

     void union_by_rank(int u,int v){
        int x = find_ulp(u);
        int y = find_ulp(v);
        if(x==y)return ;
        if(rank[x]>rank[y]){
            parent[y]=x;
        }else if(rank[x]<rank[y]){
            parent[x]=y;
        }else{
            parent[x]=y;
            rank[y]++;
        }
     }

    };
    int numSimilarGroups(vector<string>& strs) {
        int n =  strs.size();
        if(n==1)return 1;
        Disjoint ds(n);

        for(int i=0;i<n;i++){
            for(int k = i+1;k<n;k++){
              string x =strs[i];
           string y = strs[k];
           int cnt =0;
           for(int j=0;j<x.size();j++){
            if(x[j]!=y[j])cnt++;
           }
           if(cnt<=2){
            int a = ds.find_ulp(i);
            int b = ds.find_ulp(k);
            if(a!=b){
                ds.union_by_rank(a,b);
            }
           }
            }
        }

        
        int ans =0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)ans++;
        }
        return ans;
    }
};