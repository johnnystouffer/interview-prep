#include "../libraries.h"

using namespace std;

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
        if (q->val < p->val) { swap(q, p); }
        if (root->val >= p->val && root->val <= q->val) { return root; }
        if (root->val > q->val) { return lowestCommonAncestor(root->left, p, q); }
        return lowestCommonAncestor(root->right, p, q);
    }
};