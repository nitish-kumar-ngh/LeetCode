class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        if (n==1)return derived[0]==0;
        vector<int>o1(n,0);
        vector<int>o2(n,0);
        if (derived[0]==1){
            o1[0]=0;
            o1[1]=1;
            o2[0]=1;
            o2[1]=0;
        }else{
            o1[0]=0;
            o1[1]=0;
            o2[0]=1;
            o2[1]=1;
        }
        for (int i=1;i<n-1;i++){
            if (derived[i]==1){
                o1[i+1]=!o1[i];
                o2[i+1]=!o2[i];
            }else{
                o1[i+1]=o1[i];
                o2[i+1]=o2[i];
            }
        }
        if (derived[n-1]==1){
            if (o1[n-1]^o1[0]||o2[n-1]^o2[0]){
                return true;
            }
        }else{
               if (o1[n-1]^o1[0]==0||o2[n-1]^o2[0]==0){
                return true;
            }
        }
        return false;
    }
};