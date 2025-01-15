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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          vector<vector<int>> zig;
        if (root==NULL)return zig;
       
        int cnt=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size =q.size();
            vector<int>level;
            cnt++;
            if (cnt%2!=0){
                for(int i=0;i<size;i++){
                    TreeNode* temp=q.front();
                        q.pop();
                        if (temp->left!=NULL)q.push(temp->left);
                         if (temp->right!=NULL)q.push(temp->right);
                         level.push_back(temp->val);
                }
                zig.push_back(level);
            }else{
                 for(int i=0;i<size;i++){
                    TreeNode* temp=q.front();
                        q.pop();
                        if (temp->left!=NULL)q.push(temp->left);
                         if (temp->right!=NULL)q.push(temp->right);
                         level.push_back(temp->val);
                }
                reverse(level.begin(),level.end());
                zig.push_back(level);
            }
        }
        return zig;
    }
};