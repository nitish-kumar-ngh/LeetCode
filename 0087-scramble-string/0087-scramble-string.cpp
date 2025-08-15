class Solution {
public:
 unordered_map<string,bool>mp;
   bool f(string s1,string s2){
    if(s1==s2)return true;
    if(s1.size()!=s2.size())return false;
    int n=s1.size();
    string s= s1+"-"+s2;
    if(mp.find(s)!=mp.end())return mp[s];
    bool result = false;
    for(int i=1;i<n;i++){
        bool swap = f(s1.substr(0,i),s2.substr(n-i,i))&& f(s1.substr(i,n-i),s2.substr(0,n-i));
        if(swap){
            result = true;
            break;
        }
         bool noswap = f(s1.substr(0,i),s2.substr(0,i))&& f(s1.substr(i,n-i),s2.substr(i,n-i));
        if(noswap){
            result = true;
            break;
        }
    }
    return mp[s]=result;
   }
    bool isScramble(string s1, string s2) {
       return f(s1,s2);
    }
};