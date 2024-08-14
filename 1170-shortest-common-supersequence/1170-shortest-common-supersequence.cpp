class Solution {
public:
    
    string shortestCommonSupersequence(string str1, string str2) {
        int r = str1.size();
        int c = str2.size();
        int t[r+1][c+1];
        memset(t,-1,sizeof(t));
        for (int i=0;i<r+1;i++){
            t[i][0]=0;
        }
         for (int i=0;i<c+1;i++){
            t[0][i]=0;
        }
        
         for (int i=1;i<r+1;i++){
            for (int j=1;j<c+1;j++){
               if (str1[i-1]==str2[j-1]){
                t[i][j] = 1+ t[i-1][j-1];
               }else{
                 t[i][j] =max(t[i][j-1],t[i-1][j]) ;
               }
            }
           
        }


       int i=r;
       int j=c;
       string s="";
       while(i>0 && j>0){
          if (str1[i-1]==str2[j-1]){
            s=s+str1[i-1];
            i--;
            j--;
          }else{
            if (t[i][j-1]>t[i-1][j]){
                s=s+str2[j-1];
                j--;
            }else{
                s=s+str1[i-1];
                i--;
            }
          }
       }
       while(i>0){
        s=s+str1[i-1];
        i--;
       }
       while(j>0){
        s=s+str2[j-1];
        j--;
       }
       reverse(s.begin(),s.end());
       return s;



        for (int i=0;i<r+1;i++){
            for (int j=0;j<c+1;j++){
                cout<<t[i][j]<<" ";
            }
            cout<<"\n";
        }
        return "";
    }
};