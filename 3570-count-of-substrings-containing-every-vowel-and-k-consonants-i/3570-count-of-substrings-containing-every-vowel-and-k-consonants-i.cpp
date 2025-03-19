class Solution {
public:
    int countOfSubstrings(string word, int l) {
        int ans=0;
        for (int i=0;i<word.size();i++){
            
            for(int j=i;j<word.size();j++){
                if (j-i+1>=l+5){
                    unordered_map<char,int>ch;
                    for(int k=i;k<=j;k++){
                    ch[word[k]]++;
                    }
                    int cnt =0,cnt2=0;
                   if (ch.find('a')!=ch.end() && ch.find('e')!=ch.end() && ch.find('i')!=ch.end()&&ch.find('o')!=ch.end()&&ch.find('u')!=ch.end()){
                    for(auto v:ch){
                        if (v.first !='a'&&v.first !='e'&&v.first !='i'&&v.first !='o'&&v.first !='u'){
                            cnt+=v.second;
                           
                            }else{
                                cnt2++;
                            }
                    }
                   
                   }
                    if (cnt==l &&cnt2==5){
                         cout<<"("<<i<<j<<") ";
                        ans++;}
                }
            }
        }
        return ans;
    }
};