class Solution {
public:
    bool f(string s, string t){
        if(s.size()!=t.size())return false;
        int pivot =-1;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                pivot=i;
                break;
            }
        }
        if(pivot==-1)return false;
        if(s.substr(0,pivot)==t.substr(0,pivot) && s.substr(pivot+1)==t.substr(pivot+1) )return true;

       return false;
    }
    int countSubstrings(string s, string t) {
        unordered_map<int,vector<string>>mp;
        for(int i=0;i<t.size();i++){
            string k="";
            for(int j=i;j<t.size();j++){
                k+=t[j];
                mp[k.size()].push_back(k);
            }
        }
        int cnt =0;
         for(int i=0;i<s.size();i++){
            string k="";
            for(int j=i;j<s.size();j++){
                k+=s[j];
                for(auto v:mp[k.size()]){
                    cnt+=f(k,v);
                }
            }
        }
      return cnt;
    }
};