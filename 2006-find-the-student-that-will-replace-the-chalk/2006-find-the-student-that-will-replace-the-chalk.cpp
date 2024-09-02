class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i=0;
      long long int s=0;
       for (int i=0;i<chalk.size();i++){
        s=s+chalk[i];
       }
       k=k%s;
       while(k>=chalk[i]){
         k=k-chalk[i];
         ++i;
         if (i==chalk.size()){
           i=i%chalk.size();
        }
       }
       return i;
    }
};