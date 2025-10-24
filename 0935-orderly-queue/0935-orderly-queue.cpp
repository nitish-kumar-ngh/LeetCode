class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        } 
        string result =s;
        for(int len =1;len<s.size();len++){
            string ans = s.substr(len)+s.substr(0,len);
            result=min(result,ans);
        }
        return result;
    }
};