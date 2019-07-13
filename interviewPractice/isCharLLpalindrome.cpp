bool isPalindrome(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len += 1;
        temp = temp->next;
    }
    int cnt = 0;
    stack<int> stk;
    while (cnt <= len/2)
    {
        cnt += 1;
        stk.push(temp->data);
        temp = temp->next;
    }
    if (len&1)
        temp = temp->next;
    while (temp != NULL)
    {
        if (stk.top() != temp->data)
            return 0;
        stk.pop();
    }
    return 1;
}
