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
     vector<TreeNode*> solve(int s,int e){
        if(s>e)return {NULL};
        if(s==e){
            TreeNode*root = new TreeNode(s);
            return {root};
        }
         vector<TreeNode*>result;
        for(int i = s;i<=e;i++){
               vector<TreeNode*>left=  solve(s,i-1);
                vector<TreeNode*>right = solve(i+1,e);
                for(auto it:left){
                    for(auto it1:right){
                        TreeNode*root = new TreeNode(i);
                        root->left = it;
                        root->right=it1;
                        result.push_back(root);

                                            }
                }

        }
        return result;
     }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
        
    }
};