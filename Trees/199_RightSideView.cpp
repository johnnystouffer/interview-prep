#include <vector>

using namespace std;

/**
 * 199. Right Side View Tree
 * 
 * This was a tricky one to start (mostly because the question 
 * was not well described) 
 * 
 * However the solution is doing a DFS of BFS depending on which
 * you think is better. BFS is more intuitive because of level
 * order search, but I believe you can write simpler and 
 * easier to read code with DFS
 * 
 * I have included both ways so you can see the difference.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * DFS WAY
 */
class DFS {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> finalNodes;
        traverse(root, finalNodes, 0);
        return finalNodes;
    }

    void traverse(TreeNode* root, vector<int>& levels, int level) {
        if (!root) {
            return;
        }

        if (levels.size() == level) {
            levels.push_back(root->val);
        }

        traverse(root->right, levels, level+1);
        traverse(root->left, levels, level+1);
        return;
    }
};

/**
 * BFS WAY
 */
class BFS {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> finalNodes;
        traverse(root, finalNodes, 0);
        return finalNodes;
    }

    void traverse(TreeNode* root, vector<int>& levels, int level) {
        if (!root) {
            return;
        }

        if (levels.size() == level) {
            levels.push_back(root->val);
        }

        traverse(root->right, levels, level+1);
        traverse(root->left, levels, level+1);
        return;
    }
};