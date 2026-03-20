#include <stdlib.h>


typedef struct {
    struct TreeNode** data;
    int top;
} Stack;

Stack* createStack(int size) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (struct TreeNode**)malloc(size * sizeof(struct TreeNode*));
    s->top = -1;
    return s;
}

void push(Stack* s, struct TreeNode* node) {
    s->data[++(s->top)] = node;
}

struct TreeNode* pop(Stack* s) {
    return s->data[(s->top)--];
}

struct TreeNode* peek(Stack* s) {
    return s->data[s->top];
}

int isEmpty(Stack* s) {
    return s->top == -1;
}
void pushLeft(Stack* s, struct TreeNode* node) {
    while (node) {
        push(s, node);
        node = node->left;
    }
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize) {
    int capacity = 10000; 
    int* result = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    Stack* s1 = createStack(capacity);
    Stack* s2 = createStack(capacity);

    pushLeft(s1, root1);
    pushLeft(s2, root2);

    while (!isEmpty(s1) || !isEmpty(s2)) {
        Stack* s;

        if (isEmpty(s1)) {
            s = s2;
        } else if (isEmpty(s2)) {
            s = s1;
        } else {
            if (peek(s1)->val < peek(s2)->val)
                s = s1;
            else
                s = s2;
        }

        struct TreeNode* node = pop(s);
        result[(*returnSize)++] = node->val;

        pushLeft(s, node->right);
    }

    return result;
}