#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct Node *child;
};

struct Node {
    struct TreeNode *data;
    struct Node *prev, *next;
};

struct TreeNode *insert(struct TreeNode **root, struct TreeNode *node, int d) {
    struct TreeNode *newNode = malloc(sizeof(struct TreeNode));
    newNode -> data = d;
    newNode -> child = NULL;
    if (*root == NULL) {
        *root = newNode;
        return newNode;
    }
    struct Node *tmp = malloc(sizeof(struct Node));
    tmp -> data = newNode;
    tmp -> prev = NULL;
    tmp -> next = NULL;
    if (node -> child == NULL) 
        node -> child = tmp;
    else {
        struct Node *cur = node -> child;
        while (cur -> next != NULL) 
            cur = cur -> next;
        cur -> next = tmp;
        tmp -> prev = cur;
    }
    return newNode;
}

void preorder(struct TreeNode *root) {
    struct Node *ll = malloc(sizeof(struct Node)); //stack simulate
    ll -> data = root;
    ll -> next = NULL;
    ll -> prev = NULL;
    while (ll != NULL) {
        struct Node *top = ll;
        while (top -> next != NULL)
            top = top -> next;
        if (top == ll) 
            ll = NULL;
        else {
            top -> prev -> next = NULL;
            top -> prev = NULL;
        }
        printf("%d ", top -> data -> data);
        struct Node *cur = top -> data -> child;
        while (cur != NULL && cur -> next != NULL) // left preorder
            cur = cur -> next; // rigth preorder must forbid this loop
        while (cur != NULL) {
            struct Node *tmp = malloc(sizeof(struct Node));
            tmp -> data = cur -> data;
            tmp -> prev = NULL;
            tmp -> next = NULL;
            if (ll == NULL)
                ll = tmp;
            else {
                struct Node *j = ll;
                while (j -> next != NULL)
                    j = j -> next;
                j -> next = tmp;
                tmp -> prev = j;
            }
            cur = cur -> prev; // cur = cur -> next;(right preorder)
        }
        free(top);
    }
}

void postorder(struct TreeNode *root) {
    struct Node *ll = malloc(sizeof(struct Node)); //stack simulate
    int stack[1000] = {}, index;
    ll -> data = root;
    ll -> next = NULL;
    ll -> prev = NULL;
    while (ll != NULL) {
        struct Node *top = ll;
        while (top -> next != NULL)
            top = top -> next;
        if (top == ll) 
            ll = NULL;
        else {
            top -> prev -> next = NULL;
            top -> prev = NULL;
        }
        //printf("%d ", top -> data -> data);
        stack[index] = top -> data -> data;
        index++;
        struct Node *cur = top -> data -> child;
        //while (cur != NULL && cur -> next != NULL) 
        //    cur = cur -> next;
        while (cur != NULL) {
            struct Node *tmp = malloc(sizeof(struct Node));
            tmp -> data = cur -> data;
            tmp -> prev = NULL;
            tmp -> next = NULL;
            if (ll == NULL)
                ll = tmp;
            else {
                struct Node *j = ll;
                while (j -> next != NULL)
                    j = j -> next;
                j -> next = tmp;
                tmp -> prev = j;
            }
            cur = cur -> next; 
        }
        free(top);
    }
    while (index > 0) {
        index--;
        printf("%d ", stack[index]);
    }
}

void levelorder(struct TreeNode *root) {
    struct Node *ll = malloc(sizeof(struct Node)); //queue simulate
    int queue[1000] = {}, index;
    ll -> data = root;
    ll -> next = NULL;
    ll -> prev = NULL;
    while (ll != NULL) {
        struct Node *top = ll;
        ll = ll -> next;
        if (ll != NULL) 
            ll -> prev = NULL;
        printf("%d ", top -> data -> data);
        struct Node *cur = top -> data -> child;
        while (cur != NULL) {
            struct Node *tmp = malloc(sizeof(struct Node));
            tmp -> data = cur -> data;
            tmp -> prev = NULL;
            tmp -> next = NULL;
            if (ll == NULL)
                ll = tmp;
            else {
                struct Node *j = ll;
                while (j -> next != NULL)
                    j = j -> next;
                j -> next = tmp;
                tmp -> prev = j;
            }
            cur = cur -> next; 
        }
        free(top);
    }
}

int _depth(struct TreeNode *r, struct TreeNode *node, int d) {
    if (r == NULL)
        return 0;
    if (r == node)
        return d;
    struct Node *cur = r -> child;
    while (cur != NULL) {
        int tmp = _depth(cur -> data, node, d + 1);
        if (tmp > 0)
            return tmp;
        cur = cur -> next;
    }
    return 0;
}

int depth(struct TreeNode *root, struct TreeNode *node) {
    return _depth(root, node, 0);
}

int height(struct TreeNode *r) {
    if (r == NULL)
        return 0;
    struct Node *cur = r -> child;
    int max = 0;
    while (cur != NULL) {
        int tmp = height(cur -> data) + 1;
        if (tmp > max)
            max = tmp;
        cur = cur -> next;
    }
    return max;
}

void display(struct TreeNode *r, int d) {
    if (r == NULL)
        return;
    for (int i = 0; i < d; ++i) //seg 1
        printf("  ");
    printf("%d\n", r -> data);
    struct Node *cur = r -> child; // seg2
    while (cur != NULL) {
        display(cur -> data, d + 1);
        cur = cur -> next;
    }
    //seg1 -> seg2 == preorder seg2 -> seg1 == postorder
}

int main() {
    struct TreeNode *root = NULL;
    struct TreeNode *node1 = insert(&root, NULL, 1);
    insert(&root, node1, 2);
    struct TreeNode *node3 = insert(&root, node1, 3);
    struct TreeNode *node4 = insert(&root, node1, 4);
    insert(&root, node3, 5);
    struct TreeNode *node6 = insert(&root, node3, 6);
    insert(&root, node3, 7);
    insert(&root, node4, 8);
    struct TreeNode *node9 = insert(&root, node6, 9);
    insert(&root, node6, 10);
    insert(&root, node9, 11);
    struct TreeNode *node12 = insert(&root, node9, 12);
    insert(&root, node12, 13);
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    levelorder(root);
    printf("\n");
    printf("%d\n", depth(root, node3));
    printf("%d\n", depth(root, node6));
    printf("%d\n", depth(root, node12));
    printf("%d\n", height(root));
    printf("%d\n", height(node3));
    printf("%d\n", height(node1 -> child -> data));
    printf("%d\n", height(node4));
}
