










class Solution {
public:
    int t[100][100][100];
    int f(vector<int>& boxes,int l,int r,int k){
        if(l>r)return 0;
        if(t[l][r][k]!=-1)return t[l][r][k];
        while(r<l && boxes[r]==boxes[r-1] ){
            r--;
            k++;

        }
        t[l][r][k] = f(boxes,l,r-1,0)+(k+1)*(k+1);
        for(int i=l;i<r;i++){
            if(boxes[i]==boxes[r]){
                t[l][r][k] = max(t[l][r][k] ,f(boxes,l,i,k+1)+f(boxes,i+1,r-1,0));
            }
        }

        return t[l][r][k] ;
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memset(t,-1,sizeof(t));
        return f(boxes,0,n-1,0);

    }
};