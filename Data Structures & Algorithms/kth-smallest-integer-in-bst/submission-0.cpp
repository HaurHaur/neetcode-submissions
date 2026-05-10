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
    void dfs_k(TreeNode *cur, int target_k, int &cur_k, int &result){
        if(cur == nullptr)
            return;
        
        dfs_k(cur->left, target_k, cur_k, result);

        if(++cur_k == target_k){
            result = cur->val;
            return;
        }

        dfs_k(cur->right, target_k, cur_k, result);

        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        int cur_k = 0;
        dfs_k(root, k, cur_k, result);
        return result;
    }
};
