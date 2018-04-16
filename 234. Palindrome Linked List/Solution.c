/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int length = 0;
    struct ListNode* temp;
    temp = head;
    while (temp)
    {
        length++;
        temp = temp->next;
    }
    if (length == 0 | length == 1)
        return 1;
    char List[length];
    for (int i = 0; (i < length) & (head!=NULL); i++)
    {
        List[i] = head->val;
        head = head->next;
    }
    for (int j = 0; j < length; j++)
    {
        if (List[j] != List[length-j-1])
            return 0;
    }
    return 1;
}