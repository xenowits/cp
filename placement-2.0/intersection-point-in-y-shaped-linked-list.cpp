/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2) {
    //let's first calculate lengths of both lists
    int len1 = 0, len2 = 0;
    Node *curr = head1;
    while (curr) {
        len1 += 1;
        curr = curr->next;
    }
    curr = head2;
    while (curr) {
        len2 += 1;
        curr = curr->next;
    }
    Node *curr1 = head1, *curr2 = head2;
    if (len1 <= len2) {
        //first move (len2-len1+1) distance in list2
        for (int i = 0; i < (len2-len1); i += 1) {
            curr2 = curr2->next;
        }
    } else {
        for (int i = 0; i < (len1-len2); i += 1) {
            curr1 = curr1->next;
        }
    }

    while (curr1 != curr2) {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return curr1->data;
}
