class Solution {
public:
    bool sibset( vector<int>&freq2, vector<int>temp){
        for(int i=0;i<26;i++){
            if (temp[i]<freq2[i])return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
         vector<int>freq2(26,0);
         vector<string>ans;
         for(int i=0;i<words2.size();i++){
            string a=words2[i];
            vector<int>temp(26,0);
            for(int j=0;j<a.size();j++){
                temp[a[j]-'a']++;
                freq2[a[j]-'a']=max(freq2[a[j]-'a'],temp[a[j]-'a']);
            }
         }
         for(int k=0;k<words1.size();k++){
            string b=words1[k];
            vector<int>temp(26,0);
            for(int j=0;j<b.size();j++){
              temp[b[j]-'a']++;
            }
            if(sibset(freq2,temp)){
                ans.push_back(words1[k]);
            }
         }
         return ans;
    }
};