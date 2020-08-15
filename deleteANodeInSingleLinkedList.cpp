Node *deleteNode(Node *head, int x)
{
    //Your code here
    if (head == NULL)
    {
        return 0;
    }
    if (x == 1)
    {
        head = head->next;
        return head;
    }
    Node *temp = head, *prev = NULL;
    int cnt = 0;
    while (cnt != x - 1)
    {
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    prev->next = temp->next;
    delete (temp);
    return head;
}