#include <bits/stdc++.h>
using namespace std;
#include "BinaryTreeNode.h"

vector<int> getMax(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        vector<int> v;
        v.push_back(INT_MIN);
        return v;
    }
    vector<int> v;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    int ans = INT_MIN;
    while (!q.empty()) {
        BinaryTreeNode<int>* curr = q.front();
        q.pop();
        if (curr == NULL) {
            v.push_back(ans);
            if (q.empty()) {
                break;
            } else {
                ans = INT_MIN;
                q.push(NULL);
            }
        } else {
            ans = max(curr->data, ans);
            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
    }
    return v;
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

int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();
    vector<int> v = getMax(root);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    delete root;
}
