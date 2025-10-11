class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int>left(n,1e9);
        int p = 1e9;
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1){
                left[i]=i;
                p=i;
            }else{
                 left[i]=p;
            }
        }
        vector<int>right(n,1e9);
        p=1e9;
         for(int i=0;i<n;i++){
            if(seats[i]==1){
                right[i]=i;
                p=i;
            }else{
                 right[i]=p;
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            cout<<left[i]<<" ";
        }
        cout<<"\n";
        for(int i=0;i<n;i++){
            cout<<right[i]<<" ";
        }
        for(int i=0;i<n;i++){
            int x1 = abs(i-left[i]);
            int x2 = abs(i-right[i]);
            ans=max(ans,min(x1,x2));
        }
        return ans;
    }
};