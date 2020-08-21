#include<stack>

using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head -> next == NULL)
            return;
        
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p2->next && p2->next->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        if (p2->next)
            p2 = p2->next;
        
        
        ListNode* curPos = NULL;
        ListNode* nextPos = p1->next;
        while (nextPos!=NULL){
            ListNode* tmp = nextPos->next;
            nextPos->next = curPos;
            curPos = nextPos;
            nextPos = tmp;
        }
        p1->next = curPos;
        
        p2 = p1->next;
        p1 = head;
        
        while (p2->next){
            ListNode* tmp = p1->next;
            p1->next = p2;
            p1 = tmp;
            tmp = p2->next;
            p2->next = p1;
            p2 = tmp;
        }
        if (p1->next==curPos){
            p1->next = p2;
            p2->next = NULL;
        } else {
            p1->next->next = NULL;
            p2->next = p1->next;
            p1->next = p2;
        }        
    }
};



class SlowSolution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL)
            return;
        
        stack<ListNode*> trace;
        ListNode* p = head;
        while (p!=NULL){
            trace.push(p);
            p = p->next;
        }
        
        p = head;
        int len = trace.size();
        for (int i=0; i<(len-1)/2; ++i){
            ListNode* nextTail = trace.top();
            trace.pop();
            ListNode* nextHead = p->next;
            p -> next = nextTail;
            nextTail -> next = nextHead;
            p = nextHead;
        }
        if (len%2 == 0){
            p->next->next=NULL;
        } else {
            p->next = NULL;
        }
    }
};