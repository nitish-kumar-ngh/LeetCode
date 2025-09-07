class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long n = nums.size();
        vector<long long>pge(n,-1);
        vector<long long >nge(n,n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(st.size()>0 && nums[i]>=nums[st.top()]){
                st.pop();
            }
            if(st.size()>0){
                pge[i]=st.top();
            }
            st.push(i);
        }
        while(st.size()>0){
            st.pop();
        }
        for(int i =n-1;i>=0;i--){
            while(st.size()>0 && nums[i]>=nums[st.top()]){
                st.pop();
            }
            if(st.size()>0)nge[i]=st.top();
            st.push(i);
        }
        long long ans =0;
        for(int i =0;i<n;i++){
            if(pge[i]!=-1 && nge[i]!=n){
                ans++;
            }
        }
        return ans;
    }
};