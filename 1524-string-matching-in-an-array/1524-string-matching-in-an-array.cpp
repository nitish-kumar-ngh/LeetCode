class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string>word;
        int n= words.size();
        vector<int>vis(n,0);
        for (int i=0;i<words.size();i++){
            string a=words[i];
            if(vis[i]==0){
            for (int x=0;x<a.size();x++){
                string n="";
                for(int y=x;y<a.size();y++){
                    n+=a[y];
                    for (int k=0;k<words.size();k++){
                        if (k==i)continue;
                        if(words[k]==n){
                            word.insert(n);
                            vis[k]=1;
                            }
                    }

                }
            }}
        }
   vector<string>ans;
   for (auto c:word){
      ans.push_back(c);


   }


      return ans;
    }
};