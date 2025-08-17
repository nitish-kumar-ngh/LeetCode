class Solution {
public:
    
    bool p(string k){
        string t=k;
        reverse(k.begin(),k.end());
        return t==k;
    }
    // int f(string s,int idx){
    //     if(idx>=s.size())return t[idx]= 0;
    //     if(t[idx]!=-1)return t[idx];
    //     int ans =0;
    //     for(int i=idx;i<s.size();i++){
    //         string k = s.substr(idx,i-idx+1);
    //         if(p(k)){
    //             ans=ans+1;
    //         }
    //     }
    //     return t[idx]= ans +f(s,idx+1);
    // }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            string k="";
            for(int j=i;j<s.size();j++){
                 k+=s[j];
                 if(p(k))ans++;
            }
        }
        return ans;
    }
};