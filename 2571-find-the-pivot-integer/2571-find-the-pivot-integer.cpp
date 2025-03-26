class Solution {
public:
    int pivotInteger(int n) {
       long long int s=n*(n+1)/2;
        for (long long int i=0;i<=s;i++){
            if (i*i==s)return i;
        }
        return -1;
    }
};