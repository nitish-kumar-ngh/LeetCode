class Solution {
public:
    int compress(vector<char>& chars) {
     
         int j =0;
         string ans = "";
         for(int i=0;i<chars.size();i++){
            int cnt =0;
            while(j<chars.size() && chars[j]==chars[i]){
                cnt++;
                j++;
            }
            if(cnt ==1){
                ans=ans + chars[i];
            }else{
                ans=ans+chars[i];
                ans=ans+to_string(cnt);
            }
            i=j-1;
         }
         vector<char>result;
         for(int i =0;i<ans.size();i++){
            result.push_back(ans[i]);
         }
         chars=result;
        return ans.size();
    }
};