int isLengthEvenOrOdd(struct Node* head)
{
    Node* temp = head;
    int count = 0;
    while( temp ){
        ++count;
        temp = temp->next;
    }
    //
//cout << count << "here\n";
return (1&count);
}