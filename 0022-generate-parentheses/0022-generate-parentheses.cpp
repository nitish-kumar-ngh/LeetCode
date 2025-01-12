class Solution {
public:
    vector<string>ans;
    bool check(string s){
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if (st.empty()||s[i]=='('){
                st.push(s[i]);
            }
            if (s[i]==')'){
                if (st.top()=='(')st.pop();
                else return false;
            }
        }
        return st.empty();
    }
    void f(int n,string s){
        if (s.size()==2*n){
           if (check(s))ans.push_back(s);
            return;
        }
        f(n,s+'(');
        f(n,s+')');
    }
    vector<string> generateParenthesis(int n) {
        f(n,"");
        return ans;
    }
};