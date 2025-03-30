class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]].push_back(i);
        }
        set<pair<int,int>>v;
        for (int i=0;i<s.size();i++){
         v.insert({mp[s[i]][0],mp[s[i]][mp[s[i]].size()-1]});
        }
        vector<pair<int,int>>vi(v.begin(),v.end());
        sort(vi.begin(),vi.end());
           vector<pair<int,int>>ans;
        for(int i=0;i<v.size();i++){
            if (ans.empty()||ans.back().second<vi[i].first){
                ans.push_back(vi[i]);
            }else{
                ans.back().second=max(ans.back().second,vi[i].second);
            }
        }
        vector<int>ans1;
        for(int i=0;i<ans.size();i++){
            ans1.push_back(ans[i].second-ans[i].first+1);
            cout<<ans[i].first<<" "<<ans[i].second;
        }

       
        return ans1;
    }
};