int getMiddle(Node *head)
{
    if (head == NULL)
        return -1;
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && (fast->next != NULL))
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}