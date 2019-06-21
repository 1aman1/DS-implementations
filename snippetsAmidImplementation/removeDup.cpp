Node *removeDuplicates(Node *root)
{
    Node* tmp = root;
    Node* Del;
    while( tmp->next != NULL ) {
        if( tmp->data == tmp->next->data ) {
            Del = tmp->next;
            tmp->next = tmp->next->next;
        }
        else
            tmp = tmp->next;
        }
    return root;
}