class Solution {
public:
     int t[502];
    int f(vector<int>& arr,int idx,int k){
        if(idx>=arr.size())return t[idx]= 0;
        if(t[idx]!=-1)return t[idx];
        int ans = INT_MIN;
        int len = 0;
        int mini=0;
        int n =arr.size();

        for(int j =idx;j<min(idx+k,n);j++){
            len++;
            mini=max(mini,arr[j]);
            ans=max(ans,len*mini+f(arr,j+1,k));

        }
     return t[idx]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(t,-1,sizeof(t));
        int n = arr.size();
       return  f(arr,0,k);
    }
};