/*
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example:
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
 */


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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int up = 0;
            ListNode* head = NULL;
            ListNode* p = NULL;
            while(l1 != NULL || l2 != NULL) {
                int v;
                if (l1 == NULL) {
                    v = l2->val + up;
                } else if (l2 == NULL) {
                    v = l1->val + up;
                } else {
                    v = l1->val + l2-> val + up;
                }

                up = v / 10;
                v = v % 10;

                ListNode* n = new ListNode(v);
                if (head == NULL) {
                    head = n;
                    p = n;
                } else {
                    p->next = n;
                    p = n;;
                }

                if(l1) l1 = l1->next;
                if(l2) l2 = l2->next;
            }
            if (up > 0) {
                ListNode* n = new ListNode(up);
                p->next = n;
            }

            return head;

        }

        int getV(ListNode* l1) {
            ListNode* p = l1;
            int g = 1;
            int r = 0;
            while(p!= NULL) {
                r += g * p->val;
                p = p->next;
                g *= 10;
            }
            return r;
        }

        void printList(ListNode* l) {
            while (l != NULL) {
                cout << ' ' << l->val;
                l = l->next;
            }
            cout << '\n';
        }
};



int main(int argc, const char * argv[]) {
    Solution s = Solution();

    //ListNode* l1 = new ListNode(2);
    //l1->next = new ListNode(4);
    //l1->next->next = new ListNode(3);
    //s.printList(l1);
    //
    //ListNode* l2 = new ListNode(5);
    //l2->next = new ListNode(6);
    //l2->next->next = new ListNode(4);
    //s.printList(l2);

    //ListNode* res = s.addTwoNumbers(l1, l2);
    //s.printList(res);

    //ListNode* l1 = new ListNode(0);
    //ListNode* l2 = new ListNode(0);
    //ListNode* res = s.addTwoNumbers(l1, l2);
    //s.printList(res);

    ListNode* l1 = new ListNode(9);
    
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);
    l2->next->next->next->next = new ListNode(9);
    l2->next->next->next->next->next = new ListNode(9);
    l2->next->next->next->next->next->next = new ListNode(9);
    l2->next->next->next->next->next->next->next = new ListNode(9);
    l2->next->next->next->next->next->next->next->next = new ListNode(9);
    l2->next->next->next->next->next->next->next->next->next = new ListNode(9);
    s.printList(l2);

    ListNode* res = s.addTwoNumbers(l1, l2);
    s.printList(res);
}

