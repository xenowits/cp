//CONCEPT: USE DOWN POINTERS AS FINAL LINKERS
//ie A ->down = B . B -> down = C and so on

Node* merge(Node *a, Node *b) {
    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }
    
    Node *result;
    if (a->data <= b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    result->next = NULL;

    //MERGE COMPLETES
    return result;
}

/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root) {
    if (root == NULL || root->next == NULL) {
        return root;
    }
    return merge(root, flatten(root->next));
}
