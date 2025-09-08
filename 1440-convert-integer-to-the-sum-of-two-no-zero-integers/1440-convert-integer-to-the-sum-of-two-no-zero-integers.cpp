class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            int a =i;
            int b = n-i;
            int cnt =0;
            int cnt1=0;
             while(a>0){
                int l= a%10;
                if(l==0 )cnt++;
                a=a/10;
             }
              while(b>0){
                int l= b%10;
                if(l==0 )cnt1++;
                b=b/10;
             }
             if(cnt==0 && cnt1==0){
                return {i,n-i};
             }
        }
        return {};
    }
};