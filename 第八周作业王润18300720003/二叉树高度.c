int height(struct TreeNode* root){
	if(root==NULL) return 0;
	else if(height(root->left)>=height(root->right))
		return height(root->left)+1;
	else return height(root->right)+1;
}