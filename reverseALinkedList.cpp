Node *reverseList(Node *head)
{
    if (head->next == NULL)
        return head;
    Node *q = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return q;
}
