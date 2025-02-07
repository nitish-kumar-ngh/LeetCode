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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
       // st.push(root);
        TreeNode*node=root;
        while(true){
               if (node){
                st.push(node);
                node=node->left;
               }else{
                if(st.size()==0)break;
               ans.push_back(st.top()->val);
                node=st.top();
                st.pop();
                node=node->right;
               }
        }
        return ans;
    }
};