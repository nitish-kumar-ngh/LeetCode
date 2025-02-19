class Solution {
public:
    priority_queue<string,vector<string>,greater<string>>ans;
    void f(int i,int n,string temp,vector<int>&vis){
        if(temp.size()==n){
           ans.push(temp);
           return;
        }
       if (temp.size()>=1){
          if (temp[i-1]!='a' && i!=0) f(i+1,n,temp+"a",vis);
        if (temp[i-1]!='b' && i!=0) f(i+1,n,temp+"b",vis);
         if ( temp[i-1]!='c' ) f(i+1,n,temp+"c",vis);
       }else{
         f(i+1,n,temp+"a",vis);
         f(i+1,n,temp+"b",vis);
         f(i+1,n,temp+"c",vis);
       }
      
      
    }
    string getHappyString(int n, int k) {
        vector<int>vis(n,0);
        f(0,n,"",vis);
        int cnt=0;
        while(ans.size()>0){
             auto c=ans.top();
             cnt++;
             if(cnt==k)return c;
             ans.pop();
        }
        return "";

    }
};