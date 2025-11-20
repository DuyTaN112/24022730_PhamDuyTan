#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* buildTreePreIn(vector<int>& pre, int preL, int preR,
    vector<int>& in, int inL, int inR,
    unordered_map<int, int>& pos) {

    if (preL > preR || inL > inR) return NULL;

    int rootVal = pre[preL];
    Node* root = new Node(rootVal);

    int k = pos[rootVal];
    int leftSize = k - inL;

    root->left = buildTreePreIn(pre, preL + 1, preL + leftSize,
        in, inL, k - 1, pos);

    root->right = buildTreePreIn(pre, preL + leftSize + 1, preR,
        in, k + 1, inR, pos);

    return root;
}

Node* buildTreePostIn(vector<int>& post, int postL, int postR,
    vector<int>& in, int inL, int inR,
    unordered_map<int, int>& pos) {

    if (postL > postR || inL > inR) return NULL;

    int rootVal = post[postR];
    Node* root = new Node(rootVal);

    int k = pos[rootVal];
    int leftSize = k - inL;

    root->left = buildTreePostIn(post, postL, postL + leftSize - 1,
        in, inL, k - 1, pos);

    root->right = buildTreePostIn(post, postL + leftSize, postR - 1,
        in, k + 1, inR, pos);

    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    vector<int> pre = { 3, 9, 20, 15, 7 };
    vector<int> in = { 9, 3, 15, 20, 7 };

    unordered_map<int, int> pos1;
    for (int i = 0; i < in.size(); i++) pos1[in[i]] = i;

    Node* root1 = buildTreePreIn(pre, 0, pre.size() - 1, in, 0, in.size() - 1, pos1);

    cout << "=== Build from Preorder + Inorder ===\n";
    cout << "Preorder: "; preorder(root1);  cout << "\n";
    cout << "Inorder: "; inorder(root1);    cout << "\n";
    cout << "Postorder: "; postorder(root1); cout << "\n\n";

    vector<int> post = { 9, 15, 7, 20, 3 };

    unordered_map<int, int> pos2;
    for (int i = 0; i < in.size(); i++) pos2[in[i]] = i;

    Node* root2 = buildTreePostIn(post, 0, post.size() - 1, in, 0, in.size() - 1, pos2);

    cout << "=== Build from Postorder + Inorder ===\n";
    cout << "Preorder: "; preorder(root2);  cout << "\n";
    cout << "Inorder: "; inorder(root2);    cout << "\n";
    cout << "Postorder: "; postorder(root2); cout << "\n";

    return 0;
}
