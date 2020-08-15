int getCount(struct Node *head)
{

    //Code here
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}