class Solution {
public:
    class Disjoint{
        public:
        vector<int>parent;
        vector<int>rank;
        Disjoint(int n){
            parent.resize(n,0);
            rank.resize(n,0);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int find_ulp(int x){
            if(x==parent[x])return x;
            return parent[x]=find_ulp(parent[x]);
        }
        void union_by_rank(int u,int v){
            int ulp_u = find_ulp(u);
            int ulp_v= find_ulp(v);
            if(ulp_u==ulp_v)return;
           
                if(ulp_u>ulp_v){
                    parent[ulp_u]=ulp_v;
                    rank[ulp_v]++;
                }else{
                    parent[ulp_v]=ulp_u;
                    rank[ulp_u]++;
                }
            }

            
        

    };
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        Disjoint ds(26);
        for(int i=0;i<s1.size();i++){
            int u = s1[i]-'a';
            int v = s2[i]-'a';
            if(ds.find_ulp(u)!=ds.find_ulp(v)){
                ds.union_by_rank(u,v);
            }
        }
        string ans="";
        for(int i=0;i<baseStr.size();i++){
           int x= ds.find_ulp(baseStr[i]-'a');
           ans+=char(x+'a');
        }
        return ans;
    }
};