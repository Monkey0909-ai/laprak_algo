#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

int diameter = 0;

int height(Node* root) {
    if (root == NULL)
        return -1;

    int lh = height(root->left);
    int rh = height(root->right);

    diameter = max(diameter, lh + rh + 2);

    return max(lh, rh) + 1;
}

int main() {
    int N;
    cin >> N;

    Node* root = NULL;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    height(root);

    cout << diameter << endl;

    return 0;
}