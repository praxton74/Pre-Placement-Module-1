Node *mergeLists(Node *l1, Node *l2) {
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    if(l1->data <= l2->data) {
        l1->bottom = mergeLists(l1->bottom, l2);
        return l1;
    }
    else {
        l2->bottom = mergeLists(l1, l2->bottom);
        return l2;
    }
}

Node *flatten(Node *root) {
    if(!root || !root->next)
        return root;
    return mergeLists(root, flatten(root->next));
}
