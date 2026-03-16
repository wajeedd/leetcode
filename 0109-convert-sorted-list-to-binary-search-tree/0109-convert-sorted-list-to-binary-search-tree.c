struct TreeNode* buildBST(struct ListNode* head, struct ListNode* tail){
    if(head == tail)
        return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while(fast != tail && fast->next != tail){
        slow = slow->next;
        fast = fast->next->next;
    }

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = slow->val;

    root->left = buildBST(head, slow);
    root->right = buildBST(slow->next, tail);

    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    return buildBST(head, NULL);
}