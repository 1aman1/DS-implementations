int countNodesinLoop(struct Node *head)
{
    Node* fast;
    Node* slow;
    int loopExists = 0, counter = 0;
    fast = slow = head;
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            loopExists = 1;
            break;
        }
    }
    if(loopExists) {
        /*
        fast = fast->next;
        while( fast != slow ) {
            counter++;
            fast = fast->next;
        }
        */
        
        do{fast = fast->next;}while(slow != fast &&  ++counter);
        return counter+1;
    }
    else 
    return 0;
}