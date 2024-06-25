class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){//
        if (parent[x]==x)return x;
        return parent[x]=find(parent[x]);

    }
    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if (x_parent==y_parent) return ;
        if (rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }else if (rank[y_parent]>rank[x_parent]){
            parent[x_parent]=y_parent;
        }else {
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for (int i=0;i<n;i++){
            parent[i]=i;
        }
        for (auto x:edges){
            int a=x[0];
            int b=x[1];
            int apapa=find(a);
            int bpapa=find(b);
            if (apapa != bpapa)Union(a,b);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int papaji=find(i);
            mp[papaji]++;
        }
        //
        long long result=0;
        long long remainingcomponet=n;
        for (auto y:mp){
            int d=y.second;
            result+= d *(remainingcomponet-d);
            remainingcomponet-=d;
        }
        
        return result;
    }
};