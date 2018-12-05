/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 * Example:
 *
 * Input:
 * [
 *   1->4->5,
 *     1->3->4,
 *       2->6
 *       ]
 *       Output: 1->1->2->3->4->4->5->6
 */


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
    public:
        ListNode* merge(ListNode* list1, ListNode* list2) {
            ListNode head(0);
            ListNode* tail = &head;
            auto cur1 = list1;
            auto cur2 = list2;
            while (cur1 != nullptr && cur2 != nullptr) {
                if (cur1->val < cur2->val) {
                    tail->next = cur1;
                    tail = tail->next;
                    cur1 = cur1->next;
                } else {
                    tail->next = cur2;
                    tail = tail->next;
                    cur2 = cur2->next;
                }
            }
            auto cur = cur1 == nullptr ? cur2 : cur1;
            while (cur != nullptr) {
                tail->next = cur;
                tail = tail->next;
                cur = cur->next;
            }
            return head.next;
        }
        ListNode* mergeSort(vector<ListNode*>& lists, int start, int end) {
            if (start > end) {
                return nullptr;
            }
            if (start == end) {
                return lists[start];
            }
            int mid = start + (end - start) / 2;
            auto list1 = mergeSort(lists, start, mid);
            auto list2 = mergeSort(lists, mid + 1, end);
            return merge(list1, list2);
        }
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            int n = lists.size();
            return mergeSort(lists, 0, n - 1);
        }

};


int main(int argc, const char * argv[]) {
    Solution s = Solution();
    ListNode* A = new ListNode(1);
    A->next = new ListNode(4);
    A->next->next = new ListNode(5);

    ListNode* B = new ListNode(1);
    B->next = new ListNode(3);
    B->next->next = new ListNode(4);

    ListNode* C = new ListNode(2);
    C->next = new ListNode(6);

    vector<ListNode*> lists;
    lists.push_back(A);
    lists.push_back(B);
    lists.push_back(C);
    ListNode*  result = s.mergeKLists(lists);

    ListNode* p = result;
    while(p!= NULL) {
        cout << p->val << '\n';
        p = p->next;
    }
}

