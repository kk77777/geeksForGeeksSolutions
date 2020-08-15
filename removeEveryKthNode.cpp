Node *deleteK(Node *head, int k)
{
    //Your code here
    if (k == 0)
    {
        return head;
    }
    if (k == 1 || head == NULL)
    {
        return 0;
    }
    Node *temp = head, *prev = NULL;
    int cnt = 1;
    while (temp != NULL)
    {
        if (cnt == k)
        {
            prev->next = temp->next;
            cnt = 0;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    delete (temp);
    return head;
}