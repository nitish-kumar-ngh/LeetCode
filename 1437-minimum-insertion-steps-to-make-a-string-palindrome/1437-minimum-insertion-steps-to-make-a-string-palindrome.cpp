class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string x=s;
        reverse(s.begin(),s.end());
        string y = s;
        int t[n+1][n+1];
        memset(t,-1,sizeof(t));
        for(int i=0;i<n+1;i++){
            t[0][i]=0;
        }
        for(int i=0;i<n+1;i++){
            t[i][0]=0;
        }
        
         for (int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if (x[i-1]== y[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]= max(t[i-1][j],t[i][j-1]);
                }
            }
            
        }




     


  return x.size()-t[n][n];
    }
};