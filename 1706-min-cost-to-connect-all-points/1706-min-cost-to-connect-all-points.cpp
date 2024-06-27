class Solution {
public:
     typedef pair<int,int>P;
    int primsalgo(unordered_map<int,vector<P> >&adj,int V){
      vector<bool>inMST(V,false);
      int s=0;
       priority_queue<P,vector<P>,greater<P> >pq;
       pq.push({0,0});
       while (pq.size()>0){
        auto p=pq.top();
        pq.pop();
        int dist=p.first;
        int node=p.second;
        
        if (inMST[node]==true)continue;

        inMST[node]=true;
        s=s+dist;

        
        //neighbour
        for (auto ele:adj[node]){
            int dist=ele.second;
            int Adjnode=ele.first;
            if (inMST[Adjnode]==false){
                pq.push({dist,Adjnode});
            }
        }
       }

     return s;

    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        //graph banao
        int V=points.size();
        unordered_map<int,vector<P> >adj;
        for (int i=0;i<V;i++){
            for (int j=i+1;j<V;j++){
                int x=points[i][0];
                int y=points[i][1];
                int x_=points[j][0];
                int y_=points[j][1];
                int dist=abs(x-x_)+abs(y-y_);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
        return primsalgo(adj,V);
    }
};