/**
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * Return the following binary tree:
 *
 *     3
 *        / \
 *          9  20
 *              /  \
 *                 15   7
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
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if (preorder.empty() || inorder.empty())
                return NULL;
            TreeNode* root = new TreeNode(preorder[0]);
            if (preorder.size() ==1) {
                return root;
            }
            vector<int> inorder_left;
            vector<int> inorder_right;
            bool flag = false;
            for (int i =0; i<inorder.size();i++)
                if (inorder[i] == preorder[0]) {
                    flag = true;
                } else if (flag) {
                    inorder_right.push_back(inorder[i]);
                } else {
                    inorder_left.push_back(inorder[i]);
                }

            vector<int> preorder_left;
            vector<int> preorder_right;
            for (int i=0; i<inorder_left.size(); i++)
                preorder_left.push_back(preorder[i + 1]);
            for (int i=0; i<inorder_right.size(); i++)
                preorder_right.push_back(preorder[i + preorder_left.size() + 1]);
            root->left = buildTree(preorder_left, inorder_left);
            root->right = buildTree(preorder_right, inorder_right);
            return root;
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
    vector<int> pre = {3,9,20,15,7};
    vector<int> in = {9,3,15,20,7};

    TreeNode* root = s.buildTree(pre, in);
    s.printNodes(root);



    return 0;
}
