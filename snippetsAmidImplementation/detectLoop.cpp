bool SinglyLinkedList::detect_loop() {
	int a;
	cout<<"begin\n";
	for( a = 0; a<6; ++a ) {
		addAtEnd(a);
	}
	print();
	SLL_Node* traverse = head;
	while(traverse->next != NULL) {	
		traverse = traverse->next;
	}
	traverse->next = head->next->next;				//created a loop

	SLL_Node* slow_p = head;
	SLL_Node* fast_p = head;
				
	while (slow_p && fast_p && fast_p->next ) {
		slow_p = slow_p->next;
		fast_p  = fast_p->next->next;
		if ( slow_p == fast_p ) {
			cout<<"Found Loop";
			break;
		}
	}
	/*int c = 0;
	SLL_Node* check = head;
	while( check->next != NULL && c < 20)
	{
		cout<<check->value<<" ";
		check = check->next;
		++c;
	}*/
	
	//removal of loop
	cout<<"\nwant to remove the loop[if YES->1]";
	cin>>a;
	if(a == 1) {
		remove_loop( slow_p,fast_p );
	}
	return true;
}
