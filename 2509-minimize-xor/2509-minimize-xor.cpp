class Solution {
public:
    int minimizeXor(int num1, int num2) {
        //set bit ke position ko store karo phle
        vector<long long >v;
        int cnt =0;
        for(int i=0;i<33;i++){
            if(num1 & 1LL<<i)v.push_back(i);
            if(num2 & 1LL<<i)cnt++;
        }
        int ans =0;
        for(int i=v.size()-1;i>=0;i-- ){
             ans+=1LL<<v[i];
             cnt--;
             if(cnt ==0)break;
        }
        vector<long long >v1;
        for(int i=0;i<33;i++){
            if(!(ans & 1LL<<i))v1.push_back(i);
        }
        if (cnt!=0){
        for(int i=0;i<v1.size();i++){
            ans+=1LL<<v1[i];
             cnt--;
             if(cnt ==0)return ans;
        }
        }
        return ans;
    }
};