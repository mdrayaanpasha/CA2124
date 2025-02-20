#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *right, *left;
} node;

node *root = NULL;

void insert(int num) {
    node *n = (node *)malloc(sizeof(node));
    n->data = num;
    n->right = n->left = NULL;
    
    if (!root) {
        root = n;
        return;
    }
    
    node *tmp = root, *prev = NULL;
    while (tmp) {
        prev = tmp;
        if (tmp->data > num)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    
    if (num > prev->data)
        prev->right = n;
    else
        prev->left = n;
}

void inorder(node *n) {
    if (n) {
        inorder(n->left);
        printf("%d ", n->data);
        inorder(n->right);
    }
}

void preorder(node *n) {
    if (n) {
        printf("%d ", n->data);
        preorder(n->left);
        preorder(n->right);
    }
}

void postorder(node *n) {
    if (n) {
        postorder(n->left);
        postorder(n->right);
        printf("%d ", n->data);
    }
}

void leafs(node *n) {
    if (n) {
        if (!n->right && !n->left)
            printf("%d ", n->data);
        leafs(n->left);
        leafs(n->right);
    }
}

void search(int num) {
    node *tmp = root;
    while (tmp) {
        if (tmp->data == num) {
            printf("Found\n");
            return;
        }
        tmp = (tmp->data > num) ? tmp->left : tmp->right;
    }
    printf("Not found\n");
}

void leafSearch(int num) {
    node *tmp = root;
    while (tmp) {
        if (tmp->data == num) {
            if (!tmp->left && !tmp->right)
                printf("Found and is a leaf\n");
            else
                printf("Found but not a leaf\n");
            return;
        }
        tmp = (tmp->data > num) ? tmp->left : tmp->right;
    }
    printf("Not found\n");
}

int main() {
    int choice, num;
    while (1) {
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Leaf Nodes\n6. Search\n7. Search & Check Leaf\n8. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &num);
                insert(num);
                break;
            case 2:
                inorder(root);
                printf("\n");
                break;
            case 3:
                preorder(root);
                printf("\n");
                break;
            case 4:
                postorder(root);
                printf("\n");
                break;
            case 5:
                leafs(root);
                printf("\n");
                break;
            case 6:
                printf("Enter number to search: ");
                scanf("%d", &num);
                search(num);
                break;
            case 7:
                printf("Enter number to search and check leaf: ");
                scanf("%d", &num);
                leafSearch(num);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice, try again!\n");
        }
    }
    return 0;
}
