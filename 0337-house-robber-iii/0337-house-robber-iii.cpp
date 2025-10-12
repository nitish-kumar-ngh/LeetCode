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
    unordered_map<TreeNode* ,int>mp;
    int rob(TreeNode* root) {
        if(root == NULL) return  0;
        int x=0;
        if(mp.find(root)!=mp.end())return mp[root];
        if(root->left !=NULL){
            x = x+rob(root->left->left)+rob (root->left->right);
        }
         if(root->right !=NULL){
            x = x+rob(root->right->left)+rob (root->right->right);
        }
        int ROBKIYA = x+root->val;
        int ROBNAHIKIYA = rob(root->left)+rob(root->right);
        return mp[root]= max(ROBKIYA,ROBNAHIKIYA );
    }
};