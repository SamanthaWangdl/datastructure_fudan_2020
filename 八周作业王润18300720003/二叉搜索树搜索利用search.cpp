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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       
        insertBSThelp(root,val);
        return root;
    }
    void insertBSThelp(TreeNode*root, int val){
        TreeNode *&t=search(root,val);
        if(t==NULL)
            t=new TreeNode;
            t->val=val;
    }
    TreeNode*& search(TreeNode*&root,double val){
        if(root==NULL)return root;
        if(root!=NULL&&root->val==val)
            return root;
        if(root->val>val)
            return search(root->left,val);
        else return search(root->right,val);
    }
};