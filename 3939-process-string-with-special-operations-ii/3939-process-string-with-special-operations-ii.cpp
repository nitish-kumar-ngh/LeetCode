class Solution {
public:
    char processStr(string s, long long k) {
       
       long long  n=0;
       
       for(int i=0;i<s.size();i++){
         if(s[i]=='*'){
            n=max(0LL,n-1);
         }else if(s[i]=='#'){
            n=2*n;
         }else if(s[i]=='%'){
           continue;

         }else{
            n++;
         }
       }
       cout<<n;
      if(n<=k)return '.';
      reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
         if(s[i]=='*'){
            n++;
         }else if(s[i]=='#'){
           n=n/2;
           if(k>=n)k=k-n;
         }else if(s[i]=='%'){
            k=n-k-1;
           
         }else{
            n--;
            if(n<=k)return s[i];
         }
       }
       return '.';
        
    }
};