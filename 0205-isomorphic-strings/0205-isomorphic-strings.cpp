class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char ,vector<char>>mp;
        unordered_map<char ,vector<char>>mp1;
        for (int i=0;i<s.size();i++){
            mp[s[i]].push_back(t[i]);
        }
        for (int i=0;i<s.size();i++){
            mp1[t[i]].push_back(s[i]);
        }

        for (auto ele:mp){
            auto v=ele.second;
            if (v.size()!=1){
                for (int i=1;i<v.size();i++){
                    
                    if (v[i]!=v[i-1])return false;
                }
            }
        }
          for (auto ele:mp1){
            auto v=ele.second;
            if (v.size()!=1){
                for (int i=1;i<v.size();i++){
                    
                    if (v[i]!=v[i-1])return false;
                }
            }
        }
        
            
       
    return true;
    }
};