/**
  Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

  k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.'
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
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(!head)
                return head;
            ListNode* current = head,*next1,*pre = nullptr;
            int m = 1;
            while(m <= k && current)
            {
                next1 = current ->next;
                current ->next = pre;
                pre = current;
                current = next1;
                ++m;
            }
            if(m <= k)
            {
                while(current != head)
                {
                    ListNode* temp = pre ->next;
                    pre ->next = current;
                    current = pre;
                    pre = temp;
                }
                pre = head;
            }
            else
                head ->next = reverseKGroup(current,k);
            return pre;
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
    ListNode e =  ListNode(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    s.printNodes(&a);
    ListNode* nh = s.reverseKGroup(&a, 2);
    s.printNodes(nh);

    return 0;
}
