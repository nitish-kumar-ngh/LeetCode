class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto myComparator=[&](int a,int b){
            string s1=to_string(a);
            string s2=to_string(b);
            return s1+s2>s2+s1;
        };

        sort(nums.begin(),nums.end(),myComparator);
        string result="";
        for (auto v:nums){
            string a=to_string(v);
            result=result+a;
        }
        if (result[0]=='0')return "0";
        else return result;
    }
};