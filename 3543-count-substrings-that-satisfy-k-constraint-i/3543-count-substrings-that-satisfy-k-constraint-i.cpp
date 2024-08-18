class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
       int cnt =0;
        for (int i=0;i<s.size();i++){
            string x="";
            for(int j=i;j<s.size();j++){
                unordered_map<char,int>mp;
                  x=x+s[j];
                 // cout<<x<<" ";
                  for (int m=0;m<x.size();m++){
                    mp[x[m]]++;
                  }
                  if (mp['0']<=k ||mp['1']<=k)cnt++;

            }
        }
        return cnt;
    }
};