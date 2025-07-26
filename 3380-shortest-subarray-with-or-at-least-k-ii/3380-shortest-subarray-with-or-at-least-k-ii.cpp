class Solution {
public:
    void add(int number, vector<int>&vec){
        for(int i=0;i<32;i++){
            if(number & 1<<i)vec[i]++;
        }
    }
     void remove(int number, vector<int>&vec){
        for(int i=0;i<32;i++){
            if(number & 1<<i)vec[i]--;
        }
    }
    int getnumber( vector<int>&v){
        int num=0;
        for(int i=0;i<32;i++){
            if(v[i]>0){
                num=num | 1<<i;
            }
        }
        return num;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        vector<int>vec(32,0);
        int result = INT_MAX;
        while(j<nums.size()){
             add(nums[j],vec);
             while(i<=j && getnumber(vec)>=k){
                result = min(result,j-i+1);
                remove(nums[i],vec);
                i++;
             }

               j++;
        }
        return result==INT_MAX?-1:result;
      
    }
};