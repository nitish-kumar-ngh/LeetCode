class Solution {
public:
    bool isValid(string s) {
        stack<char>open;
        for(int i=0;i<s.size();i++){
            if (open.empty()||s[i]=='('||s[i]=='['||s[i]=='{'){
                open.push(s[i]);
            }
            if (s[i]==')'){
                if(open.top()=='(')open.pop();
                else return false;
            }
            if (s[i]==']'){
                if(open.top()=='[')open.pop();
                else return false;
            }
            if (s[i]=='}'){
                if(open.top()=='{')open.pop();
                else return false;
            }
        }
        return open.empty();

    }
};