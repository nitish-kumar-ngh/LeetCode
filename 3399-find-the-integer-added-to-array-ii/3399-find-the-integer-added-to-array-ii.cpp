class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int ans=INT_MAX;
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();i++){
             vector<int>temp = nums1;
          
            
            for(int j=i+1;j<nums1.size();j++){
                nums1[i]=1005;
                nums1[j]=1005;
                sort(nums1.begin(),nums1.end());
                set<int>s;
                for(int i=0;i<nums2.size();i++){
                    s.insert(nums2[i]-nums1[i]);
                }
                if(s.size()==1){
                     ans=min(ans, (nums2[0]-nums1[0]));
                }
               
                nums1=temp;
            }
        }
        return ans;
    }
};