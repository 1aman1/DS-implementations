bool SinglyLinkedList::remove_loop(SLL_Node* slow_p, SLL_Node* fast_p ) {
	slow_p = head;
	while( slow_p != fast_p ) {
		slow_p = slow_p->next;
		fast_p = fast_p->next; 
	}
	fast_p = fast_p->next;
	while( fast_p->next != slow_p ) {
		fast_p = fast_p->next;
	}
	fast_p->next = NULL;
	return true;
}
