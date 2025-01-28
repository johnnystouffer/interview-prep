/**
 * 226. Invert Binary Tree
 * 
 * TYhis one was actually... simpler but
 * harder to understand than Python, but
 * I think you can implement it this way in
 * Python but I just never though of it
 * 
 * Basically it has to return something in 
 * C++, so just return the node and say 
 * right = invert(left) cause that just 
 * returns the left one... weird... but 
 * I like it.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) { return nullptr; }

        TreeNode* temp = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(temp);

        return root;
    }
};