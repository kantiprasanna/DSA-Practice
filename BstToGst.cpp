// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
    void fun(TreeNode* root, int* sum){
        if(root == NULL){
            return;
        }
        fun(root -> right, sum);
        root -> val += *sum;
        *sum = root -> val;
        fun(root -> left, sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        fun(root, &sum);
        return root;
    }
};