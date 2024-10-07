class Solution {
public:
    int minLength(string s) {
        string m=s;
        while(true){
            for (int i=0;i<s.size();i++){
                 string l=s.substr(i,2);
                if (l=="AB"||l=="CD"){
                    s.erase(i,2);
                }
            }
            if (m==s)break;
            m=s;
        }
        return s.size();
    }
};