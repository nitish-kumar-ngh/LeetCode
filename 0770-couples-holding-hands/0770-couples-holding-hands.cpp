class Solution {
public:
    vector<int>parent;
    int find_parent(int x){
        if(parent[x]==x)return x;
        return parent[x]=find_parent(parent[x]);
    }
    bool union_find(int x,int y){
         int a=find_parent(x);
         int b=find_parent(y);
         if(a==b)return false;
         parent[b]=a;
         return true;
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        parent.resize(n,0);
        for(int i=0;i<n;i+=2){
            parent[row[i]]=row[i];
            parent[row[i+1]]=row[i];
        }
        int c =0;
        for(int i=0;i<n;i+=2){
            if(union_find(i,i+1))c++;
        }
        return c;

        
    }
};