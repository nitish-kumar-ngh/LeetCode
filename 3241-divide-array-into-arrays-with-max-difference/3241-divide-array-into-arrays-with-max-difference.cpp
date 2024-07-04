class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int noOfArrays=n/3;
        int x=0;
        while (noOfArrays){
              for (int i=x;i<2+x;i++){
                for (int j=i+1;j<3+x;j++){
                    if (nums[j]-nums[i]>k) return {};
                }
              }
              x=x+3;
              noOfArrays--;
              

        }
        vector<vector<int>>result;
        int y=0;
        for (int i=0;i<n-2;i+=3){
            vector<int>temp;
            for(int j=i;j<i+3;j++){
                temp.push_back(nums[j]);
            }
           
            result.push_back(temp);
        }
       return result;
    }
};