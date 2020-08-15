Node *rearrangeEvenOdd(Node *head)
{
    // Your Code here
    if (!head || !head->next)
        return head;
    Node *even = head, *odd = head->next;
    Node *head2 = head->next;

    while (even && odd && even->next && odd->next)
    {
        even->next = odd->next;
        even = even->next;
        odd->next = even->next;
        odd = odd->next;
    }
    if (odd)
        odd->next = NULL;
    even->next = head2;
    return head;
}