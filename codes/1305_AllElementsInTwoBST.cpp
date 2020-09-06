#include<vector>

using namespace std;
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;
        vector<int> result;
        midOrder(root1,res1);
        midOrder(root2,res2);
        int i=0,j=0;
        while (i<res1.size()&&j<res2.size()){
            if (res1[i]<res2[j]){
                result.push_back(res1[i++]);
            } else {
                result.push_back(res2[j++]);
            }
        }
        while (i<res1.size()){
            result.push_back(res1[i++]);
        }
        while (j<res2.size()){
            result.push_back(res2[j++]);
        }
        return result;        
    }
    
    void midOrder(TreeNode *root, vector<int> & result){
        if (root == NULL)
            return;
        midOrder(root->left,result);
        result.push_back(root->val);
        midOrder(root->right,result);
        return;
    }
};