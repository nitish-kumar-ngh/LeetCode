class Solution {
public:
    int n;
    unordered_set<string>word;
    int t[301];
    bool f (int idx,string &s){
        if(idx>=n)return true;
        if(word.find(s)!=word.end())return true;
          if(t[idx]!=-1)return t[idx];
        for(int len = 1;len<=n;len++){
            string temp = s.substr(idx,len);
            if(word.find(temp)!=word.end() && f(idx+len,s))return true;
        }
        return t[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
    memset(t,-1,sizeof(t));
      for(int i=0;i<wordDict.size();i++){
        word.insert( wordDict[i]);
      }
      n=s.size();
      return f(0,s);  
    }
};