#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

#define MAX 32

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

int minPath(Node* root) {
    if (root == NULL) return 0;
    int lft = 1 + minPath(root->left);
    int rht = 1 + minPath(root->right);
    if (lft < rht) return lft;
    return rht;
}

void countFreq(Node* root, int lvl, int cnt[]) {
    if (root == NULL) return;
    cnt[lvl]++;
    countFreq(root->left, lvl + 1, cnt);
    countFreq(root->right, lvl + 1, cnt);
}

int sumOneChild(Node *root) {
    if (root == NULL) return 0;
    int res = sumOneChild(root->left) + sumOneChild(root->right);
    if (root->left == NULL || root->right == NULL) res += root->data;
    return res;
}

int sumOnlyLeft(Node *root) {
    if (root == NULL) return 0;
    int res = sumOnlyLeft(root->left) + sumOnlyLeft(root->right);
    if (root->right == NULL) res += root->data;
    return res;
}

void findClosest(Node* root, int value, int* minDiff, Node** res) {
    if (root == NULL) return;
    int diff = abs(root->data - value);
    if (diff < *minDiff) {
        *minDiff = diff;
        *res = root;
    }
    findClosest(root->left, value, minDiff, res);
    findClosest(root->right, value, minDiff, res);
}

void process(int data[], int n) {
    BinaryTree tree;
    tree.root = NULL;
    for (int i = 0; i < n; ++i) {
        insertTree(&tree, data[i]);
    }

    printf("Binary Tree: ");
    printTree(tree.root);
    printf("\n\n");

    // 3.1
    int countNodes = minPath(tree.root);
    printf("3.1 So phan tu cua nhanh it nhat: %d\n", countNodes);

    // 3.2
    int maxLvlCnt = 0;
    int freq[MAX] = {};
    countFreq(tree.root, 1, freq);
    for (int i = 1; i < MAX; ++i) {
        if (freq[i] > maxLvlCnt) {
            maxLvlCnt = i;
        }
    }
    printf("3.2 Level %d co nhieu node nhat, %d nodes\n", maxLvlCnt, freq[maxLvlCnt]);

    //3.3
    int sum = sumOneChild(tree.root);
    printf("3.3 Tong gia tri cac node chi co mot con: %d\n", sum);

    //3.4
    int sumLeft = sumOnlyLeft(tree.root);
    printf("3.4: %d\n", sum - sumLeft);

    //3.5
    Node* res = NULL;
    int minD = 1e9;
    findClosest(tree.root, sum - sumLeft, &minD, &res);
    printf("3.5 Dia chi cua node co gia tri gan hieu nhat: %p (value = %d)\n", (void*)res, res->data);
}

int main() {
    int n;
    int data[] = {15, 11, 26, 8, 12, 20, 30, 6, 9, 14, 35};
    n = sizeof(data) / sizeof(data[0]);
    process(data, n);
    return 0;
}
