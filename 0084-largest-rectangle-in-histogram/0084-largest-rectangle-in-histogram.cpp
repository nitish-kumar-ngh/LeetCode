class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int>psi(n,0);
        vector<int>nsi(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if (st.size()==0)nsi[i]=n;
            else nsi[i]=st.top();
            st.push(i);
        }
        stack<int>st1;
        for(int i=0;i<n;i++){
            while(st1.size()>0 && heights[st1.top()]>=heights[i]){
                st1.pop();
            }
            if (st1.size()==0)psi[i]=-1;
            else psi[i]=st1.top();
            st1.push(i);
        }
          for(int i=0;i<n;i++){
            cout<<nsi[i]<<" ";
          }
          cout<<"\n";
           for(int i=0;i<n;i++){
            cout<<psi[i]<<" ";
          }
          
          int ans=0;
            for(int i=0;i<n;i++){
            int left=abs(psi[i]-i);
            int right=nsi[i]-i;
            ans=max(ans,(left+right-1)*heights[i]);
          }
          return ans;

    }
};