class Solution {
public:
    string largestOddNumber(string num) {
        int result=0;
        int idx=-1;
        for (int i=num.size()-1;i>=0;i--){
            int a=(int)(num[i]-'0');
            if (a%2!=0){
                idx=i;
                break;
                }
            
        }
        if (idx==-1)return "";
        else return num.substr(0,idx+1);
    }
};