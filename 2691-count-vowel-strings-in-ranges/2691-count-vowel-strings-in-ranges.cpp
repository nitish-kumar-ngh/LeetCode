class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>ans;
        vector<int>prefix(n+1,0);
        for (int i=0;i<words.size();i++){
           string a=words[i];
           if ((a[0]=='a'||a[0]=='e'||a[0]=='i'||a[0]=='o'||a[0]=='u')&&(a[a.size()-1]=='a'||a[a.size()-1]=='e'||a[a.size()-1]=='i'||a[a.size()-1]=='o'||a[a.size()-1]=='u')){
            prefix[i+1]=prefix[i]+1;
           }else{
             prefix[i+1]=prefix[i];
           }
        }
        for (auto v:queries){
            int x=v[0];
            int y=v[1];
            ans.push_back(prefix[y+1]-prefix[x]);

        }
        return ans;
    }
};