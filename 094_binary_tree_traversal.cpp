/**
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 *
 * Input: [1,null,2,3]
 *    1
 *        \
 *             2
 *                 /
 *                    3
 *
 *                    Output: [1,3,2]
 *                    Follow up: Recursive solution is trivial, could you do it iteratively?
 **/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        void dfs(TreeNode* root, vector<int>& ans){
            if(root==NULL)
                return ;
            dfs(root->left, ans);
            ans.push_back(root->val);
            dfs(root->right, ans);
        }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> ans;
            dfs(root, ans);
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
    TreeNode* a =  new TreeNode(1);
    a->right = new TreeNode(2);
    a->right->left = new TreeNode(3);

        s.printNodes(a);
    vector<int> result = s.inorderTraversal(a);
    for (vector<int>::iterator itn = result.begin(); itn != result.end(); ++ itn)
        cout << ' ' << *itn;

    cout << '\n';

    return 0;
}
