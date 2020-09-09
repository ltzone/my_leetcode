/**
 * Definition for a binary tree node.
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
    int sumRootToLeaf(TreeNode* root) {
        return sumRootToLeaf(root,0);
    }
    
    int sumRootToLeaf(TreeNode* root, int prevres){
        if (root == nullptr)
            return 0;
        int curres = prevres * 2 + root->val;
        if (root->left == nullptr && root->right == nullptr)
            return curres;
        int res = 0;
        if (root->left)
            res += sumRootToLeaf(root->left,curres);
        if (root->right)
            res += sumRootToLeaf(root->right,curres);
        return res;
    }
};