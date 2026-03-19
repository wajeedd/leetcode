#include <limits.h>

int minDiff = INT_MAX;
struct TreeNode* prev = NULL;

void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    if (prev != NULL) {
        int diff = root->val - prev->val;
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    prev = root;

    inorder(root->right);
}

int minDiffInBST(struct TreeNode* root) {
    minDiff = INT_MAX;
    prev = NULL;
    inorder(root);
    return minDiff;
}