using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode *foo;
        foo = new ListNode(0, head);
        ListNode *prev = foo, *cur = head;
        while (cur != nullptr && cur->next != nullptr){
            ListNode *cur2 = cur->next, *tmp1 = cur2->next;
            prev->next = cur2;
            cur2->next = cur;
            prev = cur;
            cur = tmp1;
        }
        if (cur){
            prev->next = cur;
            cur->next = nullptr;
        } else {
            prev->next = nullptr;
        }
        head = foo->next;
        delete foo;
        return head;
    }
};