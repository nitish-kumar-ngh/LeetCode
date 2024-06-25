class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>set1(begin(nums1),end(nums1));//put all unique element in set
        set<int>set2(begin(nums2),end(nums2));
        vector<int>v1;
        vector<int>v2;
        set_difference(begin(set1),end(set1),begin(set2),end(set2),back_inserter(v1));
        set_difference(begin(set2),end(set2),begin(set1),end(set1),back_inserter(v2));
        return {v1,v2};
    }
};