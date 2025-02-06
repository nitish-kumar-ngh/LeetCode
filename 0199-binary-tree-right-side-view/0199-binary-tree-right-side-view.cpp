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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return {};
           unordered_map<int,int>mp;
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        while(q.size()>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front().second;
                int verticle=q.front().first;
                q.pop();
                mp[verticle]=temp->val;
                if (temp->left)q.push({verticle+1,temp->left});
                if(temp->right)q.push({verticle+1,temp->right});
            }
        }
        vector<pair<int,int>>v;
        for(auto n:mp){
            v.push_back({n.first,n.second});
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(auto c:v){
            ans.push_back(c.second);
        }
        return ans;
    }
};