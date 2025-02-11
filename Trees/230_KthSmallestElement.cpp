/**
 * 230. Kth smallest node in a BST
 * 
 * Pretty simple one, since BST is SORTED there is no
 * need for a priority queue (woohoo) so we can do a level
 * order traversal until we hit the specific count
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
        int kthSmallest(TreeNode* root, int k) {
            int count = 0;
            return currNode(root, count, k);
        }
    
        int currNode(TreeNode* root, int& count, int target) {
            // if we have a left then we go to it until we get the first node
            if (root->left) {
                int num = currNode(root->left, count, target);
                if (num != -1) return num;
            }
    
            // once we do we increase the count
            count += 1;
    
            if (count == target) {
                return root->val;
            } 
    
            if (root->right) {
                int num = currNode(root->right, count, target);
                if (num != -1) return num;
            }    
            return -1;
        }
    };