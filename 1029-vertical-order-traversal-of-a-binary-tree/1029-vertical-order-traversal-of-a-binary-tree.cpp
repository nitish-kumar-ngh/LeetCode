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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //line method
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>mp;
        q.push({root,{0,0}});
        while(!q.empty()){
           auto x=q.front();
           q.pop();
           auto y=x.first;
           auto z=x.second.first;
           auto k=x.second.second;
           mp[z][k].insert(y->val);
           if(y->left!=NULL){
            q.push({y->left,{z-1,k+1}});
           }
            if(y->right!=NULL){
            q.push({y->right,{z+1,k+1}});
           }

        }
          vector<vector<int>>ans;
          map<int,vector<int>>m;
           //vector<vector<int>> ans;
        for(auto p: mp){
            vector<int> col;
            for(auto q: p.second){
                // Insert node values
                // into the column vector
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            // Add the column vector
            // to the final result
            ans.push_back(col);
        }
        return ans;
    }
};