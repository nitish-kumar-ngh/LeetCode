class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int a=nums1.size();
        int b=nums2.size();
        int k=0;
        cout<<a<<" "<<b;
        if (a%2==0){
            if (b%2==0){//odd
                   k=0;
            }else{
                for(int i=0;i<a;i++){
                    k=k^nums1[i];
                }
            }
            
        }else{
            if (b%2==0){
                 for(int i=0;i<b;i++){
                    k=k^nums2[i];
                }
            }else{
                for(int i=0;i<a;i++){
                    k=k^nums1[i];
                }
                for(int i=0;i<b;i++){
                    k=k^nums2[i];
                }
            }
        }
        return k;
    }
};