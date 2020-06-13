#include <bits/stdc++.h>
using namespace std;
#include "BinaryTreeNode.h"

int LCA(BinaryTreeNode <int>* root , int p, int q) {
    if(root == NULL) {
        return -1;
    }
    if(p == root->data || q == root->data){
        return root->data;
    }
    int a = LCA(root->left,p,q);
    int b = LCA(root->right,p,q);
    if (b == -1 && a != -1) {
        return a;
    } else if (a == -1 && b != -1){
        return b;
    } else if (a == -1 && b == -1){
        return -1;
    } else {
        return root->data;
    }
}

BinaryTreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter root data : " << endl;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        int leftChildData;
        cout << "Enter left child of " << front->data << endl;
        cin >> leftChildData;
        if (leftChildData != -1) {
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            q.push(leftChild);
        }

        int rightChildData;
        cout << "Enter right child of " << front->data << endl;
        cin >> rightChildData;
        if (rightChildData != -1) {
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            q.push(rightChild);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    int p, q;
    cout << "Enter p and q : " << endl;
    cin >> p >> q;
    cout << LCA(root, p, q);
    delete root;
}
