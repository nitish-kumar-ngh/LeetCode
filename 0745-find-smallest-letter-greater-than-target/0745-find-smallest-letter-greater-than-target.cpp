class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=letters[0];
        for (int i=0;i<letters.size();i++){
            char ch=letters[i];
            if (ch>target){
                ans=ch;
                break;
        }}
        return ans;
    }
};