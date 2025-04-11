class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int cnt=0;
        int i=0;
        int n=word.size();
        while(i<n){
          if (i+k<n) {
            string s=word.substr(i+k,n-(i+k));
            string x=word.substr(0,n-(i+k));
            cnt++;
            if(s==x)return cnt;
           
          }
           i=k+i;
        }
        return cnt+1;
    }
};