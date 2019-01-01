/**
 * Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
1
\
2
/
3

Output: [3,2,1]
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
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ans;
            vector<int> count;
            vector<TreeNode*> stack;
            if (root) {
                stack.push_back(root);
                count.push_back(0);
            }

            while(!stack.empty()) {
                int index = stack.size();
                if (!count[index-1] && stack[index-1]->left) {
                    count[index-1] = 1;
                    stack.push_back(stack[index-1]->left);
                    count.push_back(0);
                } else if (count[index-1] != 2 && stack[index-1]->right) {
                    count[index-1] = 2;
                    stack.push_back(stack[index-1]->right);
                    count.push_back(0);
                } else {
                    ans.push_back(stack[index-1]->val);
                    count.pop_back();
                    stack.pop_back();
                }
            }
            return ans;

        }
};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ret = s.postorderTraversal(root);
    for (vector<int>::iterator itn = ret.begin(); itn != ret.end(); ++ itn)
        cout << ' ' << *itn;
    cout << '\n';

    return 0;
}
