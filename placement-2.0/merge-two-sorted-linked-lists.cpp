Node* sortedMergeFunc (Node* a, Node* b) {
	if (a->next == NULL) {
		a->next = b;
		return a;
	}
	//We need 2 nodes in first list
	//SINCE one node from 2nd list needs to be inserted
	//between them : curr1 -> curr2 -> next1

	Node *curr1 = a, *next1 = a->next;
	Node *curr2 = b, *next2 = b->next;

	while (next1 && curr2) {	//either the first list ends or the second list ends
		if ((curr1->data <= curr2->data) && (curr2->data <= next1->data)) {
			//cool lets take curr2 into the first list
			next2 = curr2->next;

			curr1->next = curr2;
			curr2->next = next1;

			curr1 = curr2;
			curr2 = next2;
		} else {
			//no more hops - already reached last of list1
			if (next1->next == NULL) {
				//thinking point : curr2's value must be either less than curr1 - THIS IS NOT POSSIBLE
				//OR : curr2 > next1 - Yes THIS IS POSSIBLE.
				next1->next = curr2;
				return a;
			} else {
				//keep moving pointers of first list
				curr1 = curr1->next;
				next1 = next1->next;
			}
		}
	}

	return a;
}

Node* sortedMerge(Node* head_A, Node* head_B) {
    if (head_A == NULL) {
		return head_B;
	}

	if (head_B == NULL) {
		return head_A;
	}
	//First list always contains
	//the smaller data than the second one
	if (head_A->data < head_B->data) {
		return sortedMergeFunc(head_A, head_B);
	} else {
		return sortedMergeFunc(head_B, head_A);
	}

	return NULL;
}
