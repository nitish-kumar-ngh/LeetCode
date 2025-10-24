class Solution {
public:
    string f(int n){
        if(n==1)return "1";
        string ans="";
        ans=ans+f(n-1);
        int j =0;
        string result ="";
        for(int i=0;i<ans.size();i++){
            int cnt =0;
            while(j<ans.size()&& ans[j]==ans[i]){
                cnt++;
                j++;
            }
            result = result + to_string(cnt);
            result=result+ans[i];
            i=j-1;
        }
        return result;
    }
    string countAndSay(int n) {
        return f(n);
    }
};