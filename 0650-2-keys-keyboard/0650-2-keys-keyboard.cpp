class Solution {
public:
     int t[1001][1001];
    int f(int currA,int clipA,int n){
        if(currA==n){
            return 0;
        }
        if(currA>n){
            return 100000;
        }
        if(t[currA][clipA]!=-1)return t[currA][clipA];
        int cp = 1+1+f(currA+currA,currA,n);
        int p = 1+f(currA+clipA,clipA,n);
        return t[currA][clipA]=min(cp,p);
    }
    int minSteps(int n) {
        memset(t,-1,sizeof(t));
        if(n==1)return 0;
        return 1+ f(1,1,n);
    }
};