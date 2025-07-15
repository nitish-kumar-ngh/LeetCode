class Solution {
public:
    bool isValid(string word) {
        if (word.size()<3)return false;
         int v=0;
        int c =0;
        int digit =0;
        for(int i=0;i<word.size();i++){
          if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'||word[i]=='A'||word[i]=='E'||word[i]=='I'||word[i]=='O'||word[i]=='U')v++;
          else if (word[i]>='0'&&word[i]<='9')digit++;
          else if (word[i]!='@' && word[i]!='#'&&word[i]!='$')c++;
          else return false;

        }
        if(v==0 || c==0 ||v==0)return false;
        return true;
    }
};