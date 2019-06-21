void sortList(Node *head)
{
    int zero, one, two, count = 0;
    zero = one = two = 0;
    Node* trav = head;
    while( trav ){
        if( trav->data == 0 )
            zero++;
        else if( trav->data == 1 )
            one++;
        else
            two++;
        trav = trav->next;
        ++count;
    }
    trav = head;
    for( int i = 0; i < zero; ++i){
        trav->data = 0;
        trav = trav->next;
    }
    for( int i = 0; i < one; ++i){
        trav->data = 1;
        trav = trav->next;
    }
    for( int i = 0; i < two; ++i){
        trav->data = 2;
        trav = trav->next;
    }
}
