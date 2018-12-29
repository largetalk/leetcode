/**
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
 *
 * Note: Do not modify the linked list.
 *
 *  
 *
 *  Example 1:
 *
 *  Input: head = [3,2,0,-4], pos = 1
 *  Output: tail connects to node index 1
 *  Explanation: There is a cycle in the linked list, where tail connects to the second node.
 *
 *
 *  Example 2:
 *
 *  Input: head = [1,2], pos = 0
 *  Output: tail connects to node index 0
 *  Explanation: There is a cycle in the linked list, where tail connects to the first node.
 *
 *
 *  Example 3:
 *
 *  Input: head = [1], pos = -1
 *  Output: no cycle
 *  Explanation: There is no cycle in the linked list.
 *
 *
 *   
 *
 *   Follow up:
 *   Can you solve it without using extra space?
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode* l1 = head;
            ListNode* l2 = head;
            while(1) {
                if (l2 == nullptr || l2->next == nullptr)
                    return nullptr;
                l1 = l1->next;
                l2 = l2->next->next;
                if (l1 == l2)
                    break;
            }
            ListNode* ret = head;
            while(1) {
                if (l1==ret)
                    return ret;
                l1 = l1->next;
                ret = ret->next;
            }

        }
};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    ListNode* a = new ListNode(3);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(0);
    ListNode* d = new ListNode(4);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;

    ListNode* ret = s.detectCycle(a);
    cout << ret->val << '\n';

    return 0;
}
