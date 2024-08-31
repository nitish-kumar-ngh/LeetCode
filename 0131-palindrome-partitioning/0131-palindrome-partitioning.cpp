class Solution {
public:
    bool ispalindrome(int st,int e,string &s){
        string k=s.substr(st,e-st+1);
        string y=k;
        reverse(k.begin(),k.end());
        if (y==k)return true;
        else return false;
        // while(st<=e){
        //     if (s[st]==s[e]){
        //         e--;
        //         st++;
        //     }else return false;
        // }
        // return true;
    }
    void f(int idx,string s,vector<string>&path, vector<vector<string>>&res){
        if (idx==s.size()){
            res.push_back(path);
            return;

        }
        for (int i=idx;i<s.size();i++){
            if (ispalindrome(idx,i,s)){
                path.push_back(s.substr(idx,i-idx+1));
                  f(i+1,s,path,res);
                  path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       vector<vector<string>>res;
       vector<string>path;
       f(0,s,path,res);
       return res;
    }
};