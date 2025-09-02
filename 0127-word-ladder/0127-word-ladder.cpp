class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
           unordered_set<string>s(wordList.begin(),wordList.end());
          while(q.size()>0){
                 string w = q.front().first;
                 int x = q.front().second;
                 q.pop();
                 if(w==endWord)return x;

              for(int j =0;j<w.size();j++){
                char ch = w[j];
                for(char c='a';c<='z';c++){
                    w[j]=c;
                    if(s.find(w)!=s.end()){
                        q.push({w,x+1});
                        s.erase(w);
                        }

                }
                w[j]=ch;
            }
          }
           
        
         return 0;
    }
};