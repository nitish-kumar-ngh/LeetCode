class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        int m = shifts.size();
        vector<long long int>f(m,0);
        
        int l = 0 ;
        for(int i=0;i<shifts.size();i++){
          //  int r= i+1;
            f[l]+=shifts[i];
            if(i+1<m)f[i+1]-=shifts[i];
        }
        //coumulative
        for(int i=1;i<m;i++){
            f[i]=f[i]+f[i-1];
        }
        for(int i =0;i<m;i++){
            cout<<f[i]<<" ";
        }
        for(int i=0;i<s.size();i++){
          int a = (int(s[i]-'a')+f[i])%26;
            s[i]= a+'a';
        }
        return s;
    }
};