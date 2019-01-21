/**
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 *
 * Example:
 *
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 *
 *    1            <---
 *     /   \
 *     2     3         <---
 *      \     \
 *        5     4       <---
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
            vector<int> rightSideView(TreeNode* root) {
                vector<int> ans;
                if (root == NULL) {
                    return ans;
                }
                vector<TreeNode*> stack;
                stack.push_back(root);
                while(!stack.empty()) {
                    vector<TreeNode*> tmp;
                    TreeNode* node;
                    for (int i=0; i<stack.size(); i++) {
                        node = stack[i];
                        if (node->left)
                            tmp.push_back(node->left);
                        if (node->right)
                            tmp.push_back(node->right);
                    }
                    ans.push_back(node->val);
                    stack = tmp;
                }
                return ans;
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
    vector<int> ret = s.rightSideView(a);
    for (vector<int>::iterator itn = ret.begin(); itn != ret.end(); ++ itn)
        cout << ' ' << *itn;

    cout << '\n';

    return 0;
}
