class NumArray {
public:
    int n;
    vector<int>segment;
    void  buildSegment(int i,int l,int r,vector<int>& nums){
        if(l==r){
            segment[i]=nums[l];
            return;
        }
        int mid = (l+r)/2;
      buildSegment(2*i + 1, l, mid, nums);
      buildSegment(2*i + 2, mid + 1, r, nums);

        segment[i]= segment[2*i+1]+segment[2*i+2];
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        segment.resize(4*n,0);
        buildSegment(0,0,n-1,nums);

    }
    void updadeSegment(int i,int l,int r,int index, int val){
        if(l==r){
            segment[i]=val;
            return;
        }
        int mid = (l+r)/2;
        if (index <= mid) {
    updadeSegment(2*i + 1, l, mid, index, val);
} else {
    updadeSegment(2*i + 2, mid + 1, r, index, val);
}
  segment[i] = segment[2*i + 1] + segment[2*i + 2];

    }
    void update(int index, int val) {
        updadeSegment(0,0,n-1,index,val);
    }
    int getSum(int start,int end,int i,int l,int r){
        if(l>end || r<start)return 0;
        if(l>=start && r<=end){
            return segment[i];
        }
        int mid = (l+r)/2;
        return getSum(start,end,2*i+1,l,mid)+ getSum(start,end,2*i+2,mid+1,r);
    }
    int sumRange(int left, int right) {
        return getSum(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */