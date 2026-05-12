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
    bool dfs_comp(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr || subRoot == nullptr)
            return subRoot == root;

        if(root->val == subRoot->val){
            if(dfs_comp(root->left, subRoot->left) && dfs_comp(root->right, subRoot->right)){
                return true;
            }  
        }
        return false;
        

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr || subRoot == nullptr)
            return !subRoot;

        if(dfs_comp(root, subRoot))
            return true;

        else{
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
         }
    }
};
