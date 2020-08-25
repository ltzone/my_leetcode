/**
 Definition for a binary tree node.
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root!=nullptr)
            return walkSum(root,false);
        return 0;
    }
    
    int walkSum(TreeNode* root, bool isLeft){
        int result = 0;
        if (root->left != nullptr)
            result += walkSum(root->left,true);
        if (root->right != nullptr)
            result += walkSum(root->right,false);
        if (root->left == nullptr && root->right == nullptr){
            result += isLeft ? root->val : 0;
        }
        return result;
    }
};