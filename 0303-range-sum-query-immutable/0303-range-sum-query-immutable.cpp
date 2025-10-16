class NumArray {
public:
    int n;
    vector<int> segment;

    void buildSeg(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segment[i] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        buildSeg(2*i + 1, l, mid, nums);
        buildSeg(2*i + 2, mid + 1, r, nums);
        segment[i] = segment[2*i + 1] + segment[2*i + 2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segment.resize(4 * n, 0);
        if (n > 0) buildSeg(0, 0, n - 1, nums);
    }

    int get(int start, int end, int i, int l, int r) {
        if (r < start || l > end) return 0;              // no overlap
        if (l >= start && r <= end) return segment[i];   // complete overlap
        int mid = (l + r) / 2;
        return get(start, end, 2*i + 1, l, mid) +
               get(start, end, 2*i + 2, mid + 1, r);
    }

    int sumRange(int left, int right) {
        return get(left, right, 0, 0, n - 1);
    }
};
