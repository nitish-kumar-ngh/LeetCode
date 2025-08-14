class Solution {
public:
     int f(vector<int>&v){
        int n= v.size();
        vector<int>psi(n,0);
        vector<int>nsi(n,0);
        stack<int>st;
         stack<int>s;
        for(int i=n-1;i>=0;i--){
               while(s.size()>0 && v[s.top()]>=v[i])s.pop();
            if(s.size()>0)nsi[i]=s.top();
            else nsi[i]=n;
            s.push(i);
        }
        for(int i=0;i<n;i++){
            while(st.size()>0 && v[st.top()]>=v[i])st.pop();
            if(st.size()>0)psi[i]=st.top();
            else psi[i]=-1;
            st.push(i);
        }
       
        int mx=0;
         for(int i=0;i<n;i++){
            int left = abs(psi[i]-i);
            int right = nsi[i]-i;
            mx=max(mx,(left+right-1)*v[i]);
         }
         for(int i=0;i<n;i++){
          cout<<nsi[i]<<" ";
         }
         return mx;
     }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>grid(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')grid[i][j]=1;
            }
        }
        int ans =f(grid[0]);
          for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)grid[i][j]=grid[i][j]+grid[i-1][j];
                else grid[i][j]=0;
                
            }
                ans =max(ans,f(grid[i]));
            }
            
          
        
        
       
        return ans;
    }
};