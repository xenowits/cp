void solve(Node *root, int _min, int _max, bool &ok) {
    if (!ok || (root == NULL)) {
        return;
    }

    if (!(root->data <= _max && root->data >= _min)) {
        ok = false;
        return;
    }

    //if reached here - means everything is OK

    if (root->left != NULL) {
        solve(root->left, _min, min(_max, root->data)-1, ok);
    }

    if (root->right != NULL) {
        solve(root->right, max(_min, root->data)-1, _max, ok);
    }
}

// return true if the given tree is a BST, else return false
bool isBST(Node* root) {
    // Your code here
    int _max = INT_MAX, _min = INT_MIN;
    bool ok = true;
    solve(root, _min, _max, ok);
    return ok;
}
