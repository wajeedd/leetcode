int sum = 0;

void reverseInorder(struct TreeNode* root) {
    if (root == NULL) return;
    reverseInorder(root->right);
    sum += root->val;
    root->val = sum;
    reverseInorder(root->left);
}

struct TreeNode* bstToGst(struct TreeNode* root) {
    sum = 0; 
    reverseInorder(root);
    return root;
}