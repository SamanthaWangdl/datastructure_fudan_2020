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
        while(!stack.empty()) {
        if(cur!=NULL){
            vec.push_back(cur->val);
            stack.push(cur->right);
            cur=cur->left;
        }
        else{
            cur=stack.top();
            stack.pop(); }
    }
        return vec;}
};

