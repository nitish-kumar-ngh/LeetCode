class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>answer;
        int n = words.size();
        unordered_map<int,vector<int>>adj;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            string w = words[i];
            vector<int>hash(26,0);
            for(int i=0;i<w.size();i++){
                hash[w[i]-'a']++;
            }
            for(int j =i+1;j<n;j++){
                bool f =1;
            string wk = words[j];
            vector<int>hash2(26,0);
            for(int x=0;x<wk.size();x++){
                hash2[wk[x]-'a']++;
            }
                for(int k=0;k<26;k++){
                    if(hash[k]!=hash2[k]){
                     f=0;
                     break;
                    }
                }

                if(f==1 && j-i==1){
                    vis[j]=1;
                }
               
                }
            }
            for(int i=0;i<n;i++){
                if(vis[i]==0){
                    answer.push_back(words[i]);
                }
               
            }
        return answer;
       
    }
};