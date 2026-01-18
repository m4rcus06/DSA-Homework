#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct BinaryTree {
    Node* root;
} BinaryTree;

Node* makeNode(int data) {
    Node* newNode = malloc(sizeof(*newNode));
    memset(newNode, 0, sizeof(*newNode));
    newNode->data = data;
    return newNode;
}

Node* insert(Node* cur, int data) {
    if (cur == NULL) {
        return makeNode(data);
    }

    if (data < cur->data) {
        cur->left = insert(cur->left, data);
    } else {
        cur->right = insert(cur->right, data);
    }
    return cur;
}

void insertTree(BinaryTree* tree, int data) {
    tree->root = insert(tree->root, data);
}

void printTree(Node* node) {
    if (node == NULL) return;
    printTree(node->left);
    printf("%d ", node->data);
    printTree(node->right);
}

void deleteTree(Node* node) {
    if (node == NULL) return;
    deleteTree(node->left);
    deleteTree(node->right);
    free(node);
}

Node* search(Node* node, int value) {
    if (node == NULL) return NULL;
    if (value < node->data) {
        return search(node->left, value);
    } else if (value > node->data) {
        return search(node->right, value);
    }
    return node;
}

Node* leftMost(Node* cur) {
    while (cur != NULL && cur->left != NULL) cur = cur->left;
    return cur;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) return NULL;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node* newRoot = root->right;
            free(root);
            return newRoot;
        } else if (root->right == NULL) {
            Node* newRoot = root->left;
            free(root);
            return newRoot;
        }

        Node* newNode = leftMost(root->right);
        root->data = newNode->data;
        root->right = deleteNode(root->right, newNode->data);
    }
    return root;
}

void printAtLevel(Node* root, int curLvl, int lvl) {
    if (root == NULL) return;
    if (curLvl == lvl) {
        printf("%d ", root->data);
        return;
    }
    printAtLevel(root->left, curLvl + 1, lvl);
    printAtLevel(root->right, curLvl + 1, lvl);
}

void process(int data[], int n) {
    BinaryTree tree;
    tree.root = NULL;
    for (int i = 0; i < n; ++i) {
        insertTree(&tree, data[i]);
    }

    printTree(tree.root);
    printf("\n");

    //tim nut 25
    Node* found = search(tree.root, 25);
    if (found == NULL) {
        printf("Khong tim thay Node co gia tri 25\n");
    } else {
        printf("Node address: %p\n", (void*)found);
    }

    //Xoa nut co gia tri 12
    printf("Xoa nut co gia tri 12\n");
    tree.root = deleteNode(tree.root, 12);
    printTree(tree.root);
    printf("\n");

    //Chen nut co gia tri 13
    printf("Chen nut co gia tri 13\n");
    insertTree(&tree, 13);
    printTree(tree.root);
    printf("\n");

    //In ra cac nut o level 3
    printf("Cac nut o level 3: ");
    printAtLevel(tree.root, 1, 3);

    printf("\n\n");
    deleteTree(tree.root);
    tree.root = NULL;
}

int main() {
    int n;

    // 1.1
    printf("Bai 1.1\n");
    int data1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    n = sizeof(data1) / sizeof(data1[0]);
    process(data1, n);

    // 1.2
    printf("Bai 1.2\n");
    int data2[] = {50, 17, 76, 9, 23, 54, 14, 19, 72, 12, 67};
    n = sizeof(data2) / sizeof(data2[0]);
    process(data2, n);

    // 1.3
    printf("Bai 1.3\n");
    int data3[] = {15, 11, 26, 8, 12, 20, 30, 6, 9, 14, 35};
    n = sizeof(data3) / sizeof(data3[0]);
    process(data3, n);

    // 1.4
    printf("Bai 1.4\n");
    int data4[] = {3, 1, 10, 13, 5, 11, 16, 6, 15, 2, 9, 4};
    n = sizeof(data4) / sizeof(data4[0]);
    process(data4, n);

    return 0;
}
