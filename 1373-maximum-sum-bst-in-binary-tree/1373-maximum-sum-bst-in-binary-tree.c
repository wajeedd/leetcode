#include <limits.h>
#include <stdlib.h>

int maxSum = 0;

typedef struct {
    int isBST;
    int min;
    int max;
    int sum;
} Info;

Info dfs(struct TreeNode* root) {
    if (!root) {
        Info base = {1, INT_MAX, INT_MIN, 0};
        return base;
    }

    Info left = dfs(root->left);
    Info right = dfs(root->right);

    Info curr;

    if (left.isBST && right.isBST && root->val > left.max && root->val < right.min) {
        curr.isBST = 1;
        curr.sum = left.sum + right.sum + root->val;
        curr.min = (root->left) ? left.min : root->val;
        curr.max = (root->right) ? right.max : root->val;

        if (curr.sum > maxSum)
            maxSum = curr.sum;
    } else {
        curr.isBST = 0;
    }

    return curr;
}

int maxSumBST(struct TreeNode* root) {
    maxSum = 0;
    dfs(root);
    return maxSum;
}