class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int ans =0;
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //         int a= nums1[i]^nums2[j];
              
        //         ans=ans^a;
        //     }
        // }
        // return ans;
        int n = nums1.size();
        int m=nums2.size();
        if(n%2!=0 && m%2!=0){//odd
         for(int i=0;i<nums1.size();i++){
            ans= ans^nums1[i];
         }
           for(int i=0;i<nums2.size();i++){
            ans =ans^nums2[i];
         }

        }else if (n%2!=0 && m%2==0){
            for(int i=0;i<nums2.size();i++){
            ans =ans^nums2[i];
         }
        }else if (n%2==0 && m%2!=0){
            for(int i=0;i<nums1.size();i++){
            ans= ans^nums1[i];
         }
        }
        return ans;
    }
};