/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    if (node->next == NULL)
        free(node);
    else
    {
        node->val = (node->next)->val;
        node->next = (node->next)->next;
    }
}