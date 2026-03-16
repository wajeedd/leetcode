void recoverTree(struct TreeNode* root) {
    struct TreeNode *first=NULL, *second=NULL, *prev=NULL;
    struct TreeNode *curr=root, *temp;

    while(curr){
        if(curr->left){
            temp = curr->left;
            while(temp->right && temp->right != curr)
                temp = temp->right;

            if(temp->right == NULL){
                temp->right = curr;
                curr = curr->left;
            }
            else{
                temp->right = NULL;

                if(prev && prev->val > curr->val){
                    if(!first) first = prev;
                    second = curr;
                }
                prev = curr;

                curr = curr->right;
            }
        }
        else{
            if(prev && prev->val > curr->val){
                if(!first) first = prev;
                second = curr;
            }
            prev = curr;
            curr = curr->right;
        }
    }

    int t = first->val;
    first->val = second->val;
    second->val = t;
}