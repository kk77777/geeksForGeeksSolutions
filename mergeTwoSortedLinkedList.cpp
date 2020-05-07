Node *sortedMerge(Node *head1, Node *head2)
{
    // Your Code Here
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Node *head;
    if (head1->data < head2->data)
    {
        head = head1;
        head->next = sortedMerge(head1->next, head2);
    }
    else
    {
        head = head2;
        head->next = sortedMerge(head1, head2->next);
    }
    return head;
}