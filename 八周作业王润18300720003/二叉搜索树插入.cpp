**
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
    void insertBSThelp(TreeNode*& root, int val){
        if(root==NULL) 
        {root= new TreeNode;
        root->val=val;
        return;
        }
        if(root->val==val) return;
        if(root->val<val) {insertBSThelp(root->right,val);}
        else { insertBSThelp(root->left,val);}
     }
};