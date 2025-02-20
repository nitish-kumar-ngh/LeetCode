class Solution {
public:
    vector<string>ans;
    void f(int i,int n,string temp){
        if (i>=n){
              ans.push_back(temp);
              return;
        }
        f(i+1,n,temp+"1");
        f(i+1,n,temp+"0");

    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int>mp;
        for(auto x:nums){
            mp[x]=1;
        }
        int n=nums[0].size();
        f(0,n,"");
        for(auto v:ans){
           if (mp.find(v)==mp.end())return v;
        }
        return "11";
    }
};