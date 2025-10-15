class Solution {
public:
     vector<int>ch;
     
     unordered_map<char,int>mp;
     void dfs(int curr, unordered_map<int,vector<int>>&adj, string &labels,int parent){
        int before = mp[labels[curr]];
        mp[labels[curr]]++;
        for(auto &child:adj[curr]){
            if(child==parent)continue;
           dfs(child,adj,labels,curr);
            
            
        }
      
         
         ch[curr]= mp[labels[curr]]-before;
       
       //return  mp[labels[curr]];

     }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {   
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ch.resize(n,0);
      
         
        
           
           dfs(0,adj,labels,-1);
        
        
        return ch;
    }
};