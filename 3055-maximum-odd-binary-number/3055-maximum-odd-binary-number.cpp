class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if (s[i]=='1') cnt++;
        }
        if (cnt==1){
            sort(s.begin(),s.end());
            
            return s;
        }
        if (cnt>=2){
            sort(s.begin(),s.end());
            reverse(s.begin(),s.end());
        }
        for (int i=s.size()-1;i>=0;i--){
            if (s[i]=='1'){
                s[i]='0';
                s[s.size()-1]='1';
                break;
            }

        }
        return s;
    }
};