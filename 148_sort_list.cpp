/**
 * Sort a linked list in O(n log n) time using constant space complexity.

 Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
        ListNode* sortList(ListNode* head) {
            vector<int> v;
            ListNode* current = head;
            while(current)
            {
                v.push_back(current ->val);
                current = current ->next;
            }
            sort(v.begin(),v.end());
            current = head;
            int i = 0;
            while(current)
            {
                current ->val = v[i++];
                current = current ->next;
            }
            return head;
        }

};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    ListNode* result = s.sortList(head);
    return 0;
}
