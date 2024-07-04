class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,vector<int> >mp;
        for (int i=0;i<s.size();i++){
            mp[s[i]].push_back(i);
        }
        int maxi=-1;
       for (auto ele:mp){
           auto v=ele.second;
           maxi=max(maxi,(v[v.size()-1]-v[0]-1));
       }
       return maxi;
    }
};