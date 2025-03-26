class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int>v;
        while(n>0){
            int l=n%3;
            v.push_back(l);
            n=n/3;
        }
        for(int i=0;i<v.size();i++){
            if (v[i]>1)return false;
            cout<<v[i]<<" ";
        }
        return true;
    }
};