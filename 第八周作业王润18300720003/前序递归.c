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

void preorder(struct TreeNode* root, int *arr, int* index){
    if(!root) return;
    arr[(*index)++] = root->val;
    preorder(root->left, arr, index);
    preorder(root->right, arr, index);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int *arr = (int*)malloc(MAX * sizeof(int));
    preorder(root, arr, returnSize);
    return arr;
}