class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n = nums.size();
        vector<int>p(n+1,0);

        for(int i=1;i<=n;i++){
            p[i]=p[i-1]+nums[i-1];
            cout<<p[i]<<" ";
        }
        int ans = INT_MIN;
        int left =0;
            int right =0;
        for(int i=L+M;i<=n;i++){
             left = max(left,p[i-M]-p[i-M-L]);
             right = p[i]-p[i-M];
           ans=max(ans,left+right);
        }
      int temp= L;
      L=M;
     M=temp;
       left =0;
            right =0;
        for(int i=L+M;i<=n;i++){
              left = max(left,p[i-M]-p[i-M-L]);
             right = p[i]-p[i-M];
           ans=max(ans,left+right);
        }
        return ans;
    }

};