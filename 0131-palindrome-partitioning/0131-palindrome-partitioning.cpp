class Solution {
public:
 vector<vector<string>>result;
  bool ispalindrom(string s){
    string a=s;
    reverse(a.begin(),a.end());
    if(a==s)return true;
    else return false;
  }
   void f(int idx,string s,vector<string>temp){
    if (idx==s.size()){
        result.push_back(temp);
        return;
        }
    for(int i=idx;i<=s.size();i++){
        if (ispalindrom(s.substr(idx,i-idx+1))){
            temp.push_back(s.substr(idx,i-idx+1));
            f(i+1,s,temp);
            temp.pop_back();
        }
    }
   }
    vector<vector<string>> partition(string s) {
    f(0,s,{});
    return result;
    }
};