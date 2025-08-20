class Solution {
public:
     int f(int n,int idx,set<int>&s){
        if(s.size()==n)return 1;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(s.find(i)==s.end()){
                if(i%idx==0){
                s.insert(i);
               ans+= f(n,idx+1,s);
               s.erase(i);
            }else 
            if(idx%i==0){
                s.insert(i);
              ans+=  f(n,idx+1,s);
              s.erase(i);
            }
            }
         
        }
        return ans;

     }
    int countArrangement(int n) {
         set<int>s;
          return f(n,1,s);
        
       
       
       
    }
};