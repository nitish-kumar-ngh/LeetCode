class Solution {
public:
    int minFlips(int a, int b, int c) {
        vector<int>va(32,0);
        vector<int>vb(32,0);
        vector<int>vc(32,0);
        for(int i=0;i<32;i++){
            if(a &1<<i)va[i]++;
            if(b & 1<<i)vb[i]++;
            if(c & 1<<i)vc[i]++;

        }
        int ans=0;
        for(int i=0;i<32;i++){
            if(vc[i]==1){
                if(va[i]==0&&vb[i]==0)ans=ans+1;
            }else {
                if(va[i]>0 && vb[i]>0)ans=ans+2;
               else if (va[i]>0 && vb[i]==0)ans++;
                else if (va[i] ==0 && vb[i]>0)ans++;
            }
        }
        return ans;
    }
};