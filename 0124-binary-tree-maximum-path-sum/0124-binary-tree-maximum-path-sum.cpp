/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int path(TreeNode* root){
        if (root==NULL)return 0;
        return max({root->val+max({0,path(root->left),path(root->right)})});
    }
    int maxi=INT_MIN;
    int maxPathSum(TreeNode* root) {
        if (root==NULL)return -10000;
        int lh=path(root->left);
        int rh=path(root->right);
     //   maxi=max(maxi,max({root->val,root->val+lh+rh,root->val+lh,root->val+rh}));
      return  max({max({root->val,root->val+lh+rh,root->val+lh,root->val+rh}),maxPathSum(root->left),maxPathSum(root->right)});
       // return maxi;
    }
};