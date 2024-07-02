class Solution {
public:
    int numberOfMatches(int n) {
        int noOfMatches=0;
        while (n>1){
        if (n%2==0) {
            noOfMatches+=n/2;
            n=n/2;
            }else {
                noOfMatches+=n/2;
                n=(n)/2+1;
                
                
            }
    }
    return noOfMatches;
    }
};