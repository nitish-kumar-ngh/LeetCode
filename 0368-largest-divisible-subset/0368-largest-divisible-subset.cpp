class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n,1);
         vector<int>p(n,0);
         int last=0;
         int maxi=1;
         sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            p[i]=i;
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j]==0||nums[j]%nums[i]==0)&&v[j]+1>v[i]){
                  //  v[i]=max(v[j]+1,v[i]);
                  v[i]=v[j]+1;
                  p[i]=j;
                }
                if (v[i]>maxi){
                    maxi=v[i];
                    last=i;
                }
            }
        }
        cout<<last<<" ";
         for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
         }
         vector<int>ans;
       
         ans.push_back(nums[last]);
         while(p[last]!=last){
            int a=nums[p[last]];
             ans.push_back(a);
            last= p[last];
         }
         reverse(ans.begin(),ans.end());
        
         return ans;
    }
};