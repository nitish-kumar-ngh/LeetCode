class Solution {
public:
 void f(string &m,int k){
    int s=0;
   
        for (int i=0;i<m.size();i++){
            s=s+int(m[i]-'0');
        }
        
        string x=to_string(s);
        m=x;
      return;
        
   
 }
    int getLucky(string s, int k) {
        string m="";
        for(int i=0;i<s.size();i++){
            m=m+to_string(s[i]-'a'+1);
        }
          
         while (k){
            f(m,k);
            k--;
         }
         
        return stoi(m);
    }
};