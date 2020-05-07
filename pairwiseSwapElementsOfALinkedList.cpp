Node *pairWiseSwap(struct Node *head)
{
    // The task is to complete this method
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        int x = temp->data;
        temp->data = temp->next->data;
        temp->next->data = x;
        temp = temp->next->next;
    }
    return head;
}