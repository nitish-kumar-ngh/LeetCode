class Solution {
public:
   //find and union ka code likho
   vector<int >parent;
   vector<int>rank;
   int find(int x){
    if (parent[x]==x)return x;
    return parent[x]=find(parent[x]);
   }
   
   void Union(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);
    if (x_parent==y_parent)return;
    if (rank[x_parent]>rank[y_parent]){
        parent[y_parent]=x_parent;
    }else if (rank[x_parent]<rank[y_parent]){
        parent[x_parent]=y_parent;
    }else{
        parent[x_parent]=y_parent;
        rank[y_parent]++;
    }

   }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for (int i=0;i<26;i++){
            parent[i]=i;
        }
          for (auto s:equations){
            if (s[1]=='='){
                Union(s[0]-'a',s[3]-'a');
            }
        }
        for (auto s:equations){
            if (s[1]=='!'){
                int firstParent=find(s[0]-'a');
                 int secondParent=find(s[3]-'a');
                 if (firstParent==secondParent)return false;
            }
        }
        return true;
    }
};