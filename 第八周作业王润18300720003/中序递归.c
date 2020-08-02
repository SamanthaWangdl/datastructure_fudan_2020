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

void inorder(struct TreeNode* root, int *arr, int* index){
    if(!root) return;
    inorder(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorder(root->right, arr, index);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int *arr = (int*)malloc(MAX * sizeof(int));
    inorder(root, arr, returnSize);
    return arr;
}