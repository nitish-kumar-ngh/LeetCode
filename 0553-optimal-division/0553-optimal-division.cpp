class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans ;
        if(nums.size()==0)return ans;
        if(nums.size()==1)return to_string(nums[0]);
        if(nums.size()==2)return to_string(nums[0])+"/"+ to_string(nums[1]);
         ans = to_string(nums[0]);
         ans += "/(" + to_string(nums[1]);            // now "X1/(X2"
        for(int i = 2; i < nums.size(); ++i) {
                  ans += "/" + to_string(nums[i]);   // keep appending "/Xi"
        }      
        
        ans += ")";                                   // close the parentheses

        return ans;
    }
};