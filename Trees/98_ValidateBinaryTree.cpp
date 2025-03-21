#include <vector>

using namespace std;

/**
 * 98 Validate a Binary Tree
 * 
 * In order traversal basically not hard 
 * at all woohoo woohoo wowowowowowo
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
        bool isValidBST(TreeNode* root) {
            vector<int> history;
            return levelOrderBST(root, history);
        }
    
        bool levelOrderBST(TreeNode* root, vector<int>& history) {
            if (!root) { return true; }
    
            if (levelOrderBST(root->left, history)) {
                if (history.size() == 0 || root->val > history[history.size() - 1]) {
                    history.push_back(root->val);
                }
                else { return false; }
    
                return levelOrderBST(root->right, history);
            }
    
            return false;
        }
};

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

 /**
  * New and improved Version...
  * 
  * This version just stores that last number and then checks if it needs to be returned
  */
class Solution {
    public:
        std::vector<int> prev;
        bool isValidBST(TreeNode* root) {
            if (!root) return true;
    
            if(!isValidBST(root->left)) return false;
    
            if (!prev.empty() && root->val <= prev[prev.size() - 1]) return false;
    
            prev.push_back(root->val);
    
            return isValidBST(root->right);
        }
    };