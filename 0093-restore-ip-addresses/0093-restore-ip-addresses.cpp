class Solution {
public:
    vector<string> result;
    void f(int idx,string s,string ans,int cnt){
       if(cnt>4)return;
        if(idx>=s.size()){
          string k = ans.substr(0,ans.size()-1);
        if(cnt==4)  result.push_back(k);
        }

      if(s.size()-idx>=1) {
          string  a = s.substr(idx,1);
           if(a>="0" && a<="9"){
            f(idx+1,s,ans+a+".",cnt+1);
        }
      } 
      if(s.size()-idx>=2){
      string b = s.substr(idx,2);
     if(b>="10" && b<="99"){
            f(idx+2,s,ans+b+".",cnt+1);
        }
      }
       if(s.size()-idx>=3){
          string c = s.substr(idx,3);
        if(c>="100" && c<="255"){
            f(idx+3,s,ans+c+".",cnt+1);
        }
       }
       
        
    }
    vector<string> restoreIpAddresses(string s) {
        string ans="";
        f(0,s,ans,0);
        return result;
    }
};