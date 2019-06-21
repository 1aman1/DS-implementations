void pairWiseSwap(struct node *head) {
    node* temp = head;
    if( temp && temp->next ) {
        size_t copy = head->data;
        head->data = head->next->data;
        head->next->data = copy;
        pairWiseSwap(head->next->next);
    }
}