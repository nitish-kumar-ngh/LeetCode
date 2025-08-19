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
    int ans = 0;
    unordered_map<TreeNode*, pair<int,int>> mp;
    // mp[node].first  = longest ZigZag starting with left move
    // mp[node].second = longest ZigZag starting with right move

    int v(TreeNode* root, int dir) {
        if(root == NULL) return 0;

        // Check if already computed
        if(mp.count(root)) {
            if(dir == 0 && mp[root].first != -1) return mp[root].first;
            if(dir == 1 && mp[root].second != -1) return mp[root].second;
        } else {
            // initialize with -1 if first time seeing this node
            mp[root] = {-1, -1};
        }

        int answer = 0;
        if(dir == 0) {
            // last move was left → go right
            answer = 1 + v(root->right, 1);
            mp[root].first = answer;
        } else {
            // last move was right → go left
            answer = 1 + v(root->left, 0);
            mp[root].second = answer;
        }

        return answer;
    }

    void f(TreeNode* root) {
        if(root == NULL) return;
        ans = max({ans, v(root,0), v(root,1)});
        f(root->left);
        f(root->right);
    }

    int longestZigZag(TreeNode* root) {
        if(root == NULL) return 0;
        f(root);
        return ans - 1; // subtract 1 because path length = edges, not nodes
    }
};
