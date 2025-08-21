class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        vector<int>v(n,0);
        int idx = -1;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                idx=i;
            }
            if(idx==-1)v[i]=1e8;
            else v[i]=i-idx;
        }
        int idx1=-1;
          for(int i=n-1;i>=0;i--){
            if(s[i]==c){
                idx1=i;
            }
            if(idx1==-1){
                v[i]=min(v[i],1000000);
                }
            else{
                v[i]=min(v[i],abs(i-idx1));
            } 
        }
        return v;
    }
};