/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX 1024
void postorder(struct TreeNode* root, int *arr, int* index){
    if(!root) return;
    postorder(root->left, arr, index);
    postorder(root->right, arr, index);
    arr[(*index)++] = root->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *postorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int *arr = (int*)malloc(MAX * sizeof(int));
    postorder(root, arr, returnSize);
    return arr;
}