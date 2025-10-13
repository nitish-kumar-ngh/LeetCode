class Solution {
public:
     vector<vector<string>>ans;
     bool p(string s){
        string t=s;
        reverse(s.begin(),s.end());
        return s==t;
     }
    void f(int idx,string &s,vector<string>&temp){
        if(idx>=s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<s.size();i++){
            string t= s.substr(idx,i-idx+1);
            if(p(t)){
                temp.push_back(t);
                f(i+1,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        f(0,s,temp);
        return ans;
    }
};