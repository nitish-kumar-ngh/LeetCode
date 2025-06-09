class Solution {
public:
    vector<string>ans;
   void f(string s,int i,int n){
     if(s.size()==n){
        ans.push_back(s);
    }
    if(i>=n){
        return;
    }
   
    if(s.size()==0){
        f(s+'a',i+1,n);
        f(s+'b',i+1,n);
        f(s+'c',i+1,n);
    }
    if(s.size()>0){
        if(s[i-1]=='a'){
             f(s+'b',i+1,n);
            f(s+'c',i+1,n);
        }else if(s[i-1]=='b'){
             f(s+'a',i+1,n);
           f(s+'c',i+1,n);
        }else{
               f(s+'a',i+1,n);
          f(s+'b',i+1,n);
        }
    }
   }
    string getHappyString(int n, int k) {

        f("",0,n);
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        if (k<=ans.size()){
            return ans[k-1];
        }else{
            return "";
        }
    }
};