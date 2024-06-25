class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if (parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if (x_parent == y_parent)return ;
        if (rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }else if (rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }else{
            parent[x_parent]=y_parent;
            y_parent++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        for (int i=0;i<n;i++){
            parent[i]=i;
        }
        rank.resize(n,0);
        int noOfEdges=connections.size();
        int components=n;
        if (noOfEdges<n-1)return -1;
        for (auto x:connections){
            int a=x[0];
            int b=x[1];
            if (find(a)!=find(b)){
                Union(a,b);
                components--;
            }
        }
        return components-1;
    }
};