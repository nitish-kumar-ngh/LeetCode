class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans=0;
      long long  int o1=0;
      long long   int o2=0;
       long long    int e1=0;
        long long int e2=0;
        for(int i=1;i<=n;i++){
            if (i%2==0)e1++;
            else o1++;
        }
         for(int i=1;i<=m;i++){
            if (i%2==0)e2++;
            else o2++;
        }
        ans=o1*e2*1LL+e1*o2*1LL;
        return ans;
    }
};