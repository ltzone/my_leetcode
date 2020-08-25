/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* end = head;
        ListNode* p = head;
        for (int i=0;i<n;++i){
            end = end -> next;
        }
        
        if (end == nullptr) {
            p = head -> next;
            delete head;
            return p;
        }
        
        while (end->next){
            end = end -> next;
            p = p -> next;
        }
        
        end = p->next->next;
        delete p->next;
        p->next = end;
        
        return head;
    }
};