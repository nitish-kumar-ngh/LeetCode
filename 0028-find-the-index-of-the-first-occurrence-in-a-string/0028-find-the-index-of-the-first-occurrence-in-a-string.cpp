class Solution {
public:
    int strStr(string haystack, string needle) {
        unordered_map<string,int>mp;
        for(int i=0;i<haystack.size();i++){
            for(int j=i;j<haystack.size();j++){
                string ans= haystack.substr(i,j-i+1);
                if(mp.find(ans)==mp.end()){
                    mp[ans]=i;
                }
            }
        }
        if(mp.find(needle)==mp.end())return -1;
        else return mp[needle];
    }
};