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
    void helper(TreeNode* &root, int val){
        TreeNode* newNode = new TreeNode(val);
        if(!root){
            root = newNode;
        }
        else if(val < root -> val){
            if(!root -> left) root -> left = newNode;
            else insertIntoBST(root -> left, val);
        }
        else if(val > root -> val){
            if(!root -> right) root -> right = newNode;
            else insertIntoBST(root -> right, val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        helper(root, val);
        return root;
    }
};