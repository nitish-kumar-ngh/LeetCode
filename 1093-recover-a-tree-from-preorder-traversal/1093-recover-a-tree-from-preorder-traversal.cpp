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
int n;
     TreeNode* solve(string &s,int &i,int d){
        if (i>=n)return NULL;
        int j=i;
        while(j<n &&s[j]=='-' ){
            j++;
        }
        int dash=j-i;
        if (dash!=d)return NULL;
        i+=dash;
        int num=0;
        while(i<n && isdigit(s[i])){
           num=num*10+(int)(s[i]-'0');
           i++;
        }
          TreeNode*root=new TreeNode(num);
          root->left=solve(s,i,d+1);
          root->right=solve(s,i,d+1);
          return root;
     }
    TreeNode* recoverFromPreorder(string traversal) {
        n=traversal.size();
        int i=0;
        int defth=0;
        return solve(traversal,i,defth);
    }
};