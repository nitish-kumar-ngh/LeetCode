class Solution {
public:
    
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        int num=1;
        while(num<=1e9){
            string temp = to_string(num);
            sort(temp.begin(),temp.end());
            if(s==temp)return true;
            num=num*2;
        }
        return false;
    }
};