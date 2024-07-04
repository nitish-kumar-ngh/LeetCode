class Solution {
public:
    bool isPowerOfTwo(int n) {
          if(n==0 ||n<0)return false;
        while (n>0){
            if (n%2!=0 and n!=1)return false;
            n=n/2;
        }
        if (n==1 )return true;
      
        return true;
    }
};