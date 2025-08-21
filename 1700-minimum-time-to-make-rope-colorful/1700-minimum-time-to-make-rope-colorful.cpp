class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
       stack<int>st;
       int n = neededTime.size();
       int ans =0;
       for(int i=0;i<n;i++){
          while(st.size()>0 && colors[st.top()]==colors[i]){
            ans=ans+min(neededTime[st.top()],neededTime[i]);
            if(neededTime[st.top()]<neededTime[i]){
                st.pop();
                st.push(i);
                i++;
                } else i++;
           
          }
          st.push(i);
       }
       return ans;
    }
};