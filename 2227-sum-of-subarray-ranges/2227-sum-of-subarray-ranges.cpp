class Solution {
public:
    long long  int sumSubarrayMins(vector<int>& arr) {
       long long  int n=arr.size();
        vector<long long int>nse(n,0);
        vector<long long int>pse(n,0);
        stack< long long int>st;
        int mod=1000000007;
        for(long long int i=n-1;i>=0;i--){
            while(st.size()>0 && arr[st.top()]>=arr[i]){
                st.pop();

            }
            if (st.size()==0)nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }
        // for(int i=0;i<n;i++){
        //     cout<<nse[i]<<" "; 
        // }
          stack< long long int>st1;
        for(long long int i=0;i<n;i++){
            while(st1.size()>0 && arr[st1.top()]>arr[i]){
                st1.pop();

            }
            if (st1.size()==0)pse[i]=-1;
            else pse[i]=st1.top();
            st1.push(i);
        }
        for(int i=0;i<n;i++){
            cout<<pse[i]<<" "; 
        }
      long long  int ans=0;
        for (long long int i=0;i<n;i++){
          long   int left=abs(pse[i]-i);
          long   int right=abs(nse[i]-i);
            ans=ans+(left*right*arr[i]*1LL);
            
        }
        return ans;
    }
      long long  int sumSubarrayMx(vector<int>& arr) {
       long long  int n=arr.size();
        vector<long long int>nse(n,0);
        vector<long long int>pse(n,0);
        stack< long long int>st;
        int mod=1000000007;
        for(long long int i=n-1;i>=0;i--){
            while(st.size()>0 && arr[st.top()]<=arr[i]){
                st.pop();

            }
            if (st.size()==0)nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }
        // for(int i=0;i<n;i++){
        //     cout<<nse[i]<<" "; 
        // }
          stack< long long int>st1;
        for(long long int i=0;i<n;i++){
            while(st1.size()>0 && arr[st1.top()]<arr[i]){
                st1.pop();

            }
            if (st1.size()==0)pse[i]=-1;
            else pse[i]=st1.top();
            st1.push(i);
        }
        for(int i=0;i<n;i++){
            cout<<pse[i]<<" "; 
        }
      long long  int ans=0;
        for (long long int i=0;i<n;i++){
          long   int left=abs(pse[i]-i);
          long   int right=abs(nse[i]-i);
            ans=ans+(left*right*arr[i]*1LL);
            
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMx(nums)-sumSubarrayMins(nums);
    }
};