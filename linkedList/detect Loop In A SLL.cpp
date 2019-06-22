/* 
the concept utilised in detecting loop draws sense from number theory 
#Floyd Cycle finding algorithm
*/
SLL_Node* slow_p = head;
SLL_Node* fast_p = head;
				
while (slow_p && fast_p && fast_p->next ) {
		slow_p = slow_p->next;
		fast_p  = fast_p->next->next;
		if ( slow_p == fast_p ) {
			cout << "Found Loop";
			break;
  	}
} 
