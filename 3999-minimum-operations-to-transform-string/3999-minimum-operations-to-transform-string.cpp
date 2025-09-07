class Solution {
public:
    int minOperations(string s) {
        //find the smallest index char
        int mx =INT_MAX;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
             int idx = ch-'a';
          if(idx!=0)  mx=min(mx,idx);
        }
         if(mx==INT_MAX)return 0;
        return 26-mx;

    }
};