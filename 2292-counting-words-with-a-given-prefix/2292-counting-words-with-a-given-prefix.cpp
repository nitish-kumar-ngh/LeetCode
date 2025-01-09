class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        int x=pref.size();
        for (int i=0;i<words.size();i++){
            string a=words[i];
            string b=a.substr(0,x);
            if (b==pref)cnt++;
        }
        return cnt;
    }
};