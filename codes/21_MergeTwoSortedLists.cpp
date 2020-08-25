/**
 * Definition for singly-linked list.
 */
#include<climits>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *p;
        if (l1 && l2) {
            if (l1 -> val < l2 -> val) {
                head = p = l1; l1 = l1 -> next;
            } else {
                head = p = l2; l2 = l2 -> next;
            }
        } else if (!l1 && !l2){
            return nullptr;
        } else if (!l1){
            head = p = l2; l2 = l2 -> next;
        } else {
            head = p = l1; l1 = l1 -> next;
        }
        
        while (l1 && l2) {
            if (l1 -> val < l2 -> val) {
                p -> next = l1;
                l1 = l1 -> next;
            } else {
                p -> next = l2;
                l2 = l2 -> next;
            }
            p = p -> next;
        }
        if (l1)
            p -> next = l1;
        else
            p -> next = l2;
        return head;
    }
};

/** clean solution codes with dummy node */
class Solution2 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};