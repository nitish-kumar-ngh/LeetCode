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
   int level(TreeNode* root){
    if (root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
   }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==NULL)return 0;

       int a=  diameterOfBinaryTree(root->left);
       int b =  diameterOfBinaryTree(root->right);
       int c = level(root->left)+level(root->right);
       return max(c,max(b,a));

    }
};