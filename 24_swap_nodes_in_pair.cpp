/**
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
**/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p, *c, *n, *h;
        h = head;
        p = NULL;
        c = head;
        while(c != NULL &&  c->next != NULL) {
            n = c->next;
            c->next = n->next;
            n->next = c;
            if (p != NULL) {
                p->next = n;
            } else {
                h = n;
            }
            p = c;
            c = c->next;
        }
        return h;
    }

    void printNodes(ListNode* head) {
        while (head != NULL) {
            cout << head->val << endl;
            head = head->next;
        }
    }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    ListNode a =  ListNode(1);
    ListNode b =  ListNode(2);
    ListNode c =  ListNode(3);
    ListNode d =  ListNode(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;

    s.printNodes(&a);
    ListNode* nh = s.swapPairs(&a);
    s.printNodes(nh);

    return 0;
}
