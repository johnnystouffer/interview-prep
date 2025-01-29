/**
 * 235. Find the Lowest Common Ancestor of a Binary Tree
 * 
 * For this one, the concept is really not that hard, if 
 * you are between the two values you cannot really get
 * closer, and if the min is bigger than you go right, 
 * otherwise you gotta go right.
 */


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val = root->val;
        TreeNode* minNode = p->val > q->val ? q : p;
        TreeNode* maxNode = p->val > q->val ? p : q;

        if (minNode->val > val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (maxNode->val < val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;

    }
};