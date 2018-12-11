/**
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 *
 * Example:
 *
 * Given the sorted linked list: [-10,-3,0,5,9],
 *
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 *
 *       0
 *            / \
 *               -3   9
 *                  /   /
 *                   -10  5
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
        TreeNode* dfs(ListNode* node) {
            if (node == NULL)
                return NULL;
            if (node->next == NULL)
                return new TreeNode(node->val);
            ListNode* fast = node;
            ListNode* low = node;
            ListNode* last = low;
            while(fast && fast->next) {
                last = low;
                fast = fast->next->next;
                low = low->next;
            }
            fast = low->next;
            last->next = NULL;
            TreeNode* root = new TreeNode(low->val);
            if (node != low) {
                root->left = dfs(node);
            }
            root->right = dfs(fast);
            return root;
        }

            TreeNode* sortedListToBST(ListNode* head) {
                return dfs(head);
                    
                }


        void printNodes(TreeNode* root) {
            if (root != NULL) {
                cout << root->val << endl;
                printNodes(root->left);
                printNodes(root->right);
            }
        }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    ListNode* a =  new ListNode(-10);
    a->next = new ListNode(-3);
    a->next->next = new ListNode(0);
    a->next->next->next = new ListNode(5);
    a->next->next->next->next = new ListNode(9);

    TreeNode* result = s.sortedListToBST(a);
    s.printNodes(result);


    return 0;
}
