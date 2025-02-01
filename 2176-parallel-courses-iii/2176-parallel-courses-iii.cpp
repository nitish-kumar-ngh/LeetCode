class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>adj[n];
        for(auto it:relations){
            adj[it[0]-1].push_back(it[1]-1);
            sort(adj[it[0]-1].begin(),adj[it[0]-1].end());
        }
        for (int i=0;i<n;i++){
            for(auto v:adj[i]){
                cout<<v<<" ";
            }
            cout<<"\n";
        }
        cout<<")";
        vector<int>indegree(n,0);
        for(auto it:relations){
            indegree[it[1]-1]++;
        }
        queue<int>q;
        vector<int>ans(n,0);
        for (int i=0;i<n;i++){
            cout<<indegree[i]<<" "; 
            if(indegree[i]==0){
                q.push(i);
                ans[i]=time[i];
            }

        }
        
        while(q.size()>0){
            int node=q.front();
            q.pop();
            for(auto v:adj[node]){
                indegree[v]--;
                // if (ans[node]+time[v]>ans[v]){
                //     ans[v]=ans[node]+time[v];
                // }
               ans[v]=max(ans[v],ans[node]+time[v]);
               // ans[v]=max(ans[v],time[node]+time[v]);
              // ans[v]=max(ans[v],ans[node]+time[v]+time[node]);
                if(indegree[v]==0){
                    q.push(v);
                    }
            }
        }
        int answer=0;
        for(int i=0;i<ans.size();i++){ 
            answer=max(answer,ans[i]);
        }
        return answer;
    }
};