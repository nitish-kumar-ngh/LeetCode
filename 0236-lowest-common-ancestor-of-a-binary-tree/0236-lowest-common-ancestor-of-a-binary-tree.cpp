/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*>P;
    vector<TreeNode*>Q;
    bool f(TreeNode* root,TreeNode* p){
        if (root==NULL)return false;
        P.push_back(root);
        
        if (root==p)return true;
        if (f(root->left,p))return true;
        if(f(root->right,p))return true;
        P.pop_back();
        return false;
    }

    bool f2(TreeNode* root,TreeNode* p){
        if (root==NULL)return false;
        Q.push_back(root);
        
        if (root==p)return true;
        if (f2(root->left,p))return true;
        if(f2(root->right,p))return true;
        Q.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL )return NULL;
        f(root,p);
        f2(root,q);
        int i=0;
        int j=0;
        cout<<P.size()<<" "<<Q.size();
        while(i<P.size() && j<Q.size()){
            if (P[i]==Q[j]){
                i++;
                j++;
            }else{
                break;
            }
        }
        return P[i-1];
    }
};