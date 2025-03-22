class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long s1=0;
        long long s2=0;
        long long ans=0;
        if(k==0){
            if(nums1==nums2){
                return 0;
            }else{
                return -1;
            }
        }

        for(int i=0;i<nums1.size();i++){
             s1+=nums1[i];
             s2+=nums2[i];
             long long a=nums1[i]-nums2[i];
             if (a%k!=0)return -1;
             if (a>=0)ans+=a;
        }
        if (s1==s2)return ans/k;
        else return -1;
        
    }
};