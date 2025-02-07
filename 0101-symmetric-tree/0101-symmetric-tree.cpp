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
 bool isSmetrical(TreeNode*left,TreeNode*right){
    if (left==NULL || right == NULL)return left==right;
     if (left->val!=right->val)return false;
      
     if(isSmetrical(left->left,right->right)==false)return false;;
       
    if ( isSmetrical(left->right,right->left)==false)return false;
     return true;
 }
    bool isSymmetric(TreeNode* root) {
        if (root==NULL)return true;
        bool flag=isSmetrical(root->left,root->right);
        return flag;
    }
};