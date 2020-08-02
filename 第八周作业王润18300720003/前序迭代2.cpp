/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> stack;
        vector<int> vec;
        TreeNode* cur = root;
        stack.push(cur);
        while(cur!=NULL&&!stack.empty()) {
        cur=stack.top();
        stack.pop();
        vec.push_back(cur->val);
        if(cur->right!=NULL) stack.push(cur->right);
        if(cur->left!=NULL) stack.push(cur->left);
    }
        return vec;}
};

