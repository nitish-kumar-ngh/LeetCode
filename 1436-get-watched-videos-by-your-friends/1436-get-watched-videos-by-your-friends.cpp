class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
       
        unordered_map<int,vector<int>>adj;
        int n = friends.size();
        for(int i=0;i<n;i++){
            for(int x:friends[i]){
                adj[i].push_back(x);
            }
        }
       
       queue<pair<int,int>>q;
       q.push({id,0});
       vector<int>ans;
       vector<int>vis(n,0);
       vis[id]=1;

       while(q.size()>0){
        int node = q.front().first;
        int l = q.front().second;
        q.pop();
        if(l==level){
            ans.push_back(node);
        }

        for(auto &adjnode:adj[node]){
            if(vis[adjnode]==0){
                q.push({adjnode,l+1});
                vis[adjnode]=1;
            }
        }
       }
      
    
     unordered_map<string ,int>mp;
     for(int i=0;i<ans.size();i++){
        int id=ans[i];
        for(auto x:watchedVideos[id]){
           mp[x]++;
        }
     }
     vector<pair<int,string>>res;
     for(auto v:mp){
        res.push_back({v.second,v.first});
     }
     sort(res.begin(),res.end());
     vector<string>answer;
     for(int i=0;i<res.size();i++){
        answer.push_back(res[i].second);
     }
     return answer;
    }
};