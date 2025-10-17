class Solution {
public:
    typedef pair<int,int>p;
    void d(unordered_map<int,vector<int>>&adj,int src,vector<int>&dist1){
       priority_queue<p,vector<p>,greater<p>>pq;
       pq.push({0,src});
       dist1[src]=0;
       while(pq.size()>0){
        auto [d,node]=pq.top();
        pq.pop();
        for(auto &it:adj[node]){
           if(dist1[node]+1<dist1[it]){
            dist1[it]= dist1[node]+1;
            pq.push({dist1[it],it});
           }
        }
       }

    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

     unordered_map<int,vector<int>>adj;
     for(int i=0;i<edges.size();i++){
        if(edges[i]!=-1){
          adj[i].push_back(edges[i]);
        }
     }
     int n= edges.size();
     vector<int>dist1(n,1e9);
     vector<int>dist2(n,1e9);
     d(adj,node1,dist1);
     d(adj,node2,dist2);
     int ans = 1e9;
     vector<pair<int,int>>v;
     for(int i=0;i<n;i++){
        v.push_back({max(dist1[i],dist2[i]),i});
     }
     sort(v.begin(),v.end());
    
     if(v[0].first>=1e9)return -1;
     return v[0].second;
    
    }
};