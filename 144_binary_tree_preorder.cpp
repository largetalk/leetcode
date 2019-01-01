/**
 * Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
        void dfs(TreeNode* root, vector<int>& ret) {
            if (root != NULL)
                ret.push_back(root->val);
            else
                return;
            if (root->left != NULL)
                dfs(root->left, ret);
            if (root->right != NULL)
                dfs(root->right, ret);
        }

        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> ret;
            dfs(root, ret);
            return ret;
        }
};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ret = s.preorderTraversal(root);
     for (vector<int>::iterator itn = ret.begin(); itn != ret.end(); ++ itn)
            cout << ' ' << *itn;
     cout << '\n';

    return 0;
}
