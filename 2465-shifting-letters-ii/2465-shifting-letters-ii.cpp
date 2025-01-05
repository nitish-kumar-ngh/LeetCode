class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>diff(n,0);
        for (int i=0;i<shifts.size();i++){
            int x=shifts[i][0];
            int y=shifts[i][1];
            int z=shifts[i][2];
            if (z==0){
                int r=-1;
                diff[x]+=r;
               if (y+1<n) diff[y+1]-=r;
            }else {
                int  r=1;
                diff[x]+=r;
               if (y+1<n) diff[y+1]-=r;
            }
        }
        // commulicative sum 
        for (int i=1;i<n;i++){
            diff[i]=diff[i-1]+diff[i];
        }
        for (int i=0;i<n;i++){
            int d=diff[i];
            d=d%26;
            if (d<0){
                d=d+26;
            }
            s[i]=(s[i]-'a'+d)%26+'a';
        }
        return s;
    }
};