class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector< long long int>in(n,0);
        for(int i=0;i<n;i++){
            int u = i;
            int v = edges[i];
            in[v]=in[v]+u;
        }
      long long   int mx = 0;
        for(int i=0;i<n;i++){
            mx=max(mx,in[i]);
        }
         vector<int>ans;
         for(int i=0;i<n;i++){
            if(in[i]==mx ){
           ans.push_back(i);

            }
        }
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};