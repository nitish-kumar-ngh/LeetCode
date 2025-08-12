class Solution {
public:
    int f(vector<int>&v){
        int n=v.size();
        vector<int>psi(n,0);
        vector<int>nsi(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && v[st.top()]>=v[i])st.pop();
            if(st.size()>0)nsi[i]=st.top();
            else nsi[i]=n;
            st.push(i);
        }
        stack<int>s;
           for(int i=0;i<n;i++){
            while(s.size()>0 && v[s.top()]>=v[i])s.pop();
            if(s.size()>0)psi[i]=s.top();
            else psi[i]=-1;
            s.push(i);
        }
        for(int i=0;i<n;i++){
            cout<<psi[i]<<" ";
        }
        cout<<"\n";
        for(int i=0;i<n;i++){
            cout<<nsi[i]<<" ";
        }
        int ans =0;
        for(int i=0;i<n;i++){
            int left=abs(psi[i]-i);
            int right=nsi[i]-i;
            int width=left+right-1;
            int height=v[i];
            int a=min(width,height);
            ans=max(ans,a*a);
        }
        return ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<int>v;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>grid(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=matrix[i][j]-'0';
            }
        }
        int answer=0;
        answer=max(answer,f(grid[0]));
         for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==1)grid[i][j]=grid[i-1][j]+grid[i][j];
               else grid[i][j]=0;
            }
         answer=max(answer,f(grid[i]));
        }
        
         
         return answer;
    }
};