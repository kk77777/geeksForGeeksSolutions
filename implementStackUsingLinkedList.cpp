void MyStack ::push(int x)
{
    // Your Code
    StackNode *temp = new StackNode(x);

    temp->next = top;
    top = temp;
}

/* The method pop which return the element
  poped out of the stack*/
int MyStack ::pop()
{
    // Your Code
    StackNode *temp;
    if (top == NULL)
        return -1;
    temp = top;
    top = temp->next;
    return temp->data;
}