class Solution {
public:
  long long int t[100001];
  long long int t1[100001];
  long long int f2(int i,int n,vector<int>& energyDrinkB,vector<int>& energyDrinkA){
        if (i>=n)return 0;
        if (t[i]!=-1)return t[i];
        return t[i]=energyDrinkB[i]+max(f2(i+1,n,energyDrinkB,energyDrinkA),f(i+2,n,energyDrinkA,energyDrinkB));
    }
    long long int f(int i,int n ,vector<int>& energyDrinkA,vector<int>& energyDrinkB){
        if (i>=n)return 0;
        if (t1[i]!=-1)return t1[i];
        return t1[i]= energyDrinkA[i]+max(f(i+1,n,energyDrinkA,energyDrinkB),f2(i+2,n,energyDrinkB,energyDrinkA));
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        memset(t,-1,sizeof(t));
         memset(t1,-1,sizeof(t1));
        int n=energyDrinkA.size();
        return max(f(0,n,energyDrinkA,energyDrinkB),f2(0,n,energyDrinkB,energyDrinkA));
    }
};