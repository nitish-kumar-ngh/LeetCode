class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse(n,0);
        vector<int>pse(n,0);
        stack<int>st;
        int mod=1000000007;
        for(int i=n-1;i>=0;i--){
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
          stack<int>st1;
        for(int i=0;i<n;i++){
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
        for (int i=0;i<n;i++){
          long   int left=abs(pse[i]-i)%mod;
          long   int right=abs(nse[i]-i)%mod;
            ans=(ans+(((left*right)%mod)*arr[i]*1LL)%mod)%mod;
            
        }
        return ans;
    }
};