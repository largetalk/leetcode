/**
 * Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
        TreeNode* dfs(TreeNode* node) {
            if (node == NULL)
                return NULL;
            if (node->left == NULL) {
                node->right = dfs(node->right);
                return node;
            }
            TreeNode* left = dfs(node->left);
            TreeNode* right = dfs(node->right);
            node->left = NULL;
            node->right = left;
            while(left->right != NULL)
                left = left->right;
            left->right = right;
            return node;
        }
            void flatten(TreeNode* root) {
                dfs(root);

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
    TreeNode* a = new TreeNode(1);
    a->left = new TreeNode(2);
    a->left->left = new TreeNode(3);
    a->left->right = new TreeNode(4);
    a->right = new TreeNode(5);
    a->right->right = new TreeNode(6);

    s.printNodes(a);
    s.flatten(a);
    s.printNodes(a);


    return 0;
}
