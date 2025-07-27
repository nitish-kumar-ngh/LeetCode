class Solution {
public:
 int c(int num){
      int cnt =0;
      for(int i=0;i<32;i++){
        if(num & 1<<i)cnt++;
      }
      return cnt;
 }
    vector<int> countBits(int n) {
        vector<int> v;
        for(int i=0;i<=n;i++){
           v.push_back(c(i));
        }
        return v;
    }
};