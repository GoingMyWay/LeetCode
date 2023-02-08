/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int result = 0;
        bool prev = 0;
        ListNode * p = head;
        set<int> s;
        for ( auto & v : G ) { s.insert(v); }
        while ( p ) {
            bool isFound = s.count(p->val);
            if ( isFound && !prev ) result ++;
            p = p->next;
            prev = isFound;
        }
        return result;
    }
};
