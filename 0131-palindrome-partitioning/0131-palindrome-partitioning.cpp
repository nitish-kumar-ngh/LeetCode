class Solution {
public:
    vector<vector<string>>ans;
    bool p(string t){
        string k=t;
        reverse(t.begin(),t.end());
        return k==t;
    }
    void f(string s,int idx,vector<string>&temp){
        if(idx==s.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i=idx;i<s.size();i++){
            string t = s.substr(idx,i-idx+1);
            if(p(t)){
                temp.push_back(t);
                f(s,i+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
         f(s,0,temp);
         return ans;
    }
};