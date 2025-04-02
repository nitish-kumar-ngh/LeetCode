class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;
          vector<int> ans;
        for(int i=0;i<n;i++){
          int a=asteroids[i];
          if (a>0){
            st.push(a);
          }
          if (a<0){
           if (st.size()==0)ans.push_back(a);
           else{
               while(st.size()>0 && st.top()*a<0){
                int b=st.top();
                if (abs(a)==b){
                    st.pop();
                    a=0;
                }
                if (abs(a)<b)a=0;
                if (abs(a)>b){
                    st.pop();
                    if (st.size()==0)ans.push_back(a);
                }
               }
           }
          }
        }
         stack<int>st1;
        while(st.size()>0){
            int a=st.top();
            st.pop();
            st1.push(a);
        }
        while(st1.size()>0){
           int a=st1.top();
            st1.pop();
            ans.push_back(a);
        }
        return ans;
    }
};