class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>v(26,0);
        for (int i=0;i<s.size();i++){
            int x=s[i]-'a';
            v[x]++;
        }
        for (int i=0;i<s.size();i++){
            int x=s[i]-'a';
            if (v[x]==1)return i;
        }
        return -1;
    }
};